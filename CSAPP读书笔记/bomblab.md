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
