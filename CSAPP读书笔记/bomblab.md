2022年10月13日

开始着手做此lab

首先阅读了文档

发现可能要学习一下GDB调试器的使用

但我需要在此之前简单的入门一下Linux

下面附上我将要学习这些知识的链接

https://nju-projectn.github.io/ics-pa-gitbook/ics2021/linux.html   Linux入门

https://missing-semester-cn.github.io/		命令行与shell

https://www.cnblogs.com/lvdongjie/p/8994092.html	GDB用法详解

https://edu.csdn.net/skill/gml/gml-1c31834f07b04bcc9c5dff5baaa6680c?category=636&typeId=21584																			csdn上的Linux入门

我需要花费几天的时间来学习这些前缀知识

今天浅略地看了一下Linux的命令行操作

18号继续学习一下命令行，下一把顺带着把vim操作看了

然后开始学习GDB调试

今天又学习了一点点Linux

估计周末才能正式学习GDB了

26号 已经初步学完了简单的操作GDB

并且 通过看别人的视频 （比看readme快多了） 已经了解了bomb如何去完成的

今天算是这个lab的正式开始吧

摸鱼了两个星期，期间看了看Linux终端的命令行 GDB的用法

今天做了该lab的前两个phase （27号）

在做第二个phase中我发现网上有些解释此phase中的反汇编代码不是很准确

比如说读了六个数字 然后栈开辟了 28=4*7 个大小 其实最后一个多开辟的是相当于向量的.end()

用作判断条件

phase_1 了解了简单的函数调用的 汇编代码

phase_2 函数中增加了循环 编译器可以用某种手段去优化循环的边界条件

我在phase_2 函数过程中 调用的一个read函数发现了参数顺序不规则的问题，这点在书上有说到

今天在看动态规划，没用推进

30号 复习了phase_2

又发现的书上讲的很多细节

31号完成了phase_3

这个例子是关于switch的汇编

我在做的时候太过于关注汇编过后的代码

没有想到源代码其实是switch语句

考虑到编译器优化后的结果 和这个lab隐去的部分

其实硬去分析反汇编代码不是很好推出答案

应该先把代码试着还原到c语法的一个大的框架，然后进行解答

这可能是bomblab的精髓

GDB的使用也并不是很熟练

怎么去打印地址代表的值

其中间接引用的地址就是跳转表

2022.11.1 

phase_4

~~~c
Dump of assembler code for function phase_4:

=> 0x000000000040100c <+0>:	sub    $0x18,%rsp      //24个字节

   0x0000000000401010 <+4>:	lea    0xc(%rsp),%rcx	//scanf的第四个参数

   0x0000000000401015 <+9>:	lea    0x8(%rsp),%rdx  //scanf的第三个参数

   0x000000000040101a <+14>:	mov    $0x4025cf,%esi

   0x000000000040101f <+19>:	mov    $0x0,%eax

   0x0000000000401024 <+24>:	call   0x400bf0 <__isoc99_sscanf@plt>

   0x0000000000401029 <+29>:	cmp    $0x2,%eax  接受了两个参数

   0x000000000040102c <+32>:	jne    0x401035 <phase_4+41>

   0x000000000040102e <+34>:	cmpl   $0xe,0x8(%rsp)

   0x0000000000401033 <+39>:	jbe    0x40103a <phase_4+46>

   0x0000000000401035 <+41>:	call   0x40143a <explode_bomb>

   0x000000000040103a <+46>:	mov    $0xe,%edx

   0x000000000040103f <+51>:	mov    $0x0,%esi

   0x0000000000401044 <+56>:	mov    0x8(%rsp),%edi

   0x0000000000401048 <+60>:	call   0x400fce <func4>  //传了三个参数 first 0 14

   0x000000000040104d <+65>:	test   %eax,%eax

   0x000000000040104f <+67>:	jne    0x401058 <phase_4+76>

   0x0000000000401051 <+69>:	cmpl   $0x0,0xc(%rsp)

   0x0000000000401056 <+74>:	je     0x40105d <phase_4+81>

   0x0000000000401058 <+76>:	call   0x40143a <explode_bomb>

   0x000000000040105d <+81>:	add    $0x18,%rsp

   0x0000000000401061 <+85>:	ret 
~~~

通过做phase_4 懂了原来刚开始两个栈的地址其实是给scanf做参数的

然后就是这个阶段其中的func4函数 要读懂不是很简单

我去搜了答案，可能光去解释这个汇编代码 可能很乱 不是很好解释

很多解出来答案的都是逆向

直接用c解释func4的汇编代码



phase_5

~~~c
=> 0x0000000000401062 <+0>:	push   %rbx

   0x0000000000401063 <+1>:	sub    $0x20,%rsp //32字节

   0x0000000000401067 <+5>:	mov    %rdi,%rbx	//参数

   0x000000000040106a <+8>:	mov    %fs:0x28,%rax//fs这里是受保护的寄存器

   0x0000000000401073 <+17>:	mov    %rax,0x18(%rsp)//放到

   0x0000000000401078 <+22>:	xor    %eax,%eax//异或自身就为0

   0x000000000040107a <+24>:	call   0x40131b <string_length>//调用函数

   0x000000000040107f <+29>:	cmp    $0x6,%eax//说明字符长度必须为6

   0x0000000000401082 <+32>:	je     0x4010d2 <phase_5+112>

   0x0000000000401084 <+34>:	call   0x40143a <explode_bomb>

   0x0000000000401089 <+39>:	jmp    0x4010d2 <phase_5+112>

   0x000000000040108b <+41>:	movzbl (%rbx,%rax,1),%ecx //ax为0 就是把bx放到cx

   0x000000000040108f <+45>:	mov    %cl,(%rsp)

   0x0000000000401092 <+48>:	mov    (%rsp),%rdx

   0x0000000000401096 <+52>:	and    $0xf,%edx

   0x0000000000401099 <+55>:	movzbl 0x4024b0(%rdx),%edx

   0x00000000004010a0 <+62>:	mov    %dl,0x10(%rsp,%rax,1)

   0x00000000004010a4 <+66>:	add    $0x1,%rax

   0x00000000004010a8 <+70>:	cmp    $0x6,%rax

   0x00000000004010ac <+74>:	jne    0x40108b <phase_5+41>

   0x00000000004010ae <+76>:	movb   $0x0,0x16(%rsp)

   0x00000000004010b3 <+81>:	mov    $0x40245e,%esi

--Type <RET> for more, q to quit, c to continue without paging--c

   0x00000000004010b8 <+86>:	lea    0x10(%rsp),%rdi

   0x00000000004010bd <+91>:	call   0x401338 <strings_not_equal>

   0x00000000004010c2 <+96>:	test   %eax,%eax

   0x00000000004010c4 <+98>:	je     0x4010d9 <phase_5+119>

   0x00000000004010c6 <+100>:	call   0x40143a <explode_bomb>

   0x00000000004010cb <+105>:	nopl   0x0(%rax,%rax,1)

   0x00000000004010d0 <+110>:	jmp    0x4010d9 <phase_5+119>

   0x00000000004010d2 <+112>:	mov    $0x0,%eax

   0x00000000004010d7 <+117>:	jmp    0x40108b <phase_5+41>

   0x00000000004010d9 <+119>:	mov    0x18(%rsp),%rax

   0x00000000004010de <+124>:	xor    %fs:0x28,%rax

   0x00000000004010e7 <+133>:	je     0x4010ee <phase_5+140>

   0x00000000004010e9 <+135>:	call   0x400b30 <__stack_chk_fail@plt>

   0x00000000004010ee <+140>:	add    $0x20,%rsp

   0x00000000004010f2 <+144>:	pop    %rbx

   0x00000000004010f3 <+145>:	ret    

End of assembler dump.


~~~

