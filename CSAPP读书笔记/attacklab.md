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

level_2

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

