看了jyy的前两节课

深觉不完成这个项目是不行了

目前没安装中文输入法

因为不知道是否要使用图形化界面

学习了vim vimtutor循循善诱

766行



摆到了14号

订个每日任务吧

：14号 java day2结束

pa0结束 



15号java day3结束 pa0结束





粗略的配置完了vim 

开始学习makefile

18号早上五点浅浅地学完了makefile

晚上学tmux

简单地入门了tmux

又复习了git ----230119 凌晨

准备开始pa1



20号凌晨 开始着手框架代码 下午顺便把期末考试内容学了

首先是nemu/目录下的配置系统Kconfig文件 # 配置信息管理的规则 有着自定义的简单语言规则来形容

NEMU中的配置系统位于`nemu/tools/kconfig`

所以, 目前我们只需要关心配置系统生成的如下文件:

- `nemu/include/generated/autoconf.h`, 阅读C代码时使用
- `nemu/include/config/auto.conf`, 阅读Makefile时使用

filelist 通过文件列表(filelist)决定最终参与编译的源文件. 在`nemu/src`及其子目录下存在一些名为`filelist.mk`的文件, 它们会根据menuconfig的配置对如下4个变量进行维护:

- `SRCS-y` - 参与编译的源文件的候选集合

- `SRCS-BLACKLIST-y` - 不参与编译的源文件的黑名单集合

- `DIRS-y` - 参与编译的目录集合, 该目录下的所有文件都会被加入到`SRCS-y`中

- `DIRS-BLACKLIST-y` - 不参与编译的目录集合, 该目录下的所有文件都会被加入到`SRCS-BLACKLIST-y`中

  

makefile会包含项目中所有的`filelist.mk`文件 对上述4个变量的追加定义进行汇总, 最终会过滤出在`SRCS-y`中但不在`SRCS-BLACKLIST-y`中的源文件, 来作为最终参与编译的源文件的集合.



##### 编译和链接

Makefile的编译规则在`nemu/scripts/build.mk`中定义:

了解了makefile定义的变量的意义

```
$(CC) -> gcc
$@ -> /home/user/ics2021/nemu/build/obj-riscv32-nemu-interpreter/src/utils/timer.o
$< -> src/utils/timer.c
$(CFLAGS) -> 剩下的内容
```

### 准备第一个客户程序

由monitor来将要运行的程序读入到nemu中

我在`nemu/src/monitor/monitor.c`中一些

函数没找到定义

为了编写更紧凑的代码, 我们在`nemu/include/macro.h`中定义了一些专门用来对宏进行测试的宏. 例如`IFDEF(CONFIG_DEVICE, init_device());`表示, 如果定义了`CONFIG_DEVICE`, 才会调用`init_device()`函数; 而`MUXDEF(CONFIG_TRACE, "ON", "OFF")`则表示, 如果定义了`CONFIG_TRACE`, 则预处理结果为`"ON"`(`"OFF"`在预处理后会消失), 否则预处理结果为`"OFF"`.

```
init_rand()`, `init_log()`和`init_mem()
```

还是没有找到定义

init monitor 函数的行为：

执行一些全局初始化。

分析参数。

设置随机种子。

打开日志文件。

初始化内存。

初始化设备。

执行ISA相关的初始化。

将图像加载到内存中。这将覆盖内置图像。

初始化差异测试。

初始化简单调试器。

显示欢迎消息。



其中在执行ISA相关的初始化时

有`init_isa()`函数(在`nemu/src/isa/$ISA/init.c`中定义

它做两件事

第一项工作就是将一个内置的客户程序读入到内存中.

约定. 具体地, 我们让monitor直接把客户程序读入到一个固定的内存位置`RESET_VECTOR`.

 `RESET_VECTOR`的值在`nemu/include/memory/paddr.h`中定义.

第二项任务是初始化寄存器, 这是通过`restart()`函数来实现的

在C语言中我们就很自然地使用相应的结构体来描述CPU的寄存器结构. 不同ISA的寄存器结构也各不相同, 为此我们把寄存器结构体`CPU_state`的定义放在`nemu/src/isa/$ISA/include/isa-def.h`中, 并在`nemu/src/cpu/cpu-exec.c`中定义一个全局变量`cpu`.

初始化寄存器的一个重要工作就是设置`cpu.pc`的初值, 我们需要将它设置成刚才加载客户程序的内存位置, 这样就可以让CPU从我们约定的内存位置开始执行客户程序了.

对于mips32和riscv32, 它们的0号寄存器总是存放`0`, 因此我们也需要对其进行初始化.

riscv32的物理地址均从`0x80000000`开始. 因此对于mips32和riscv32, 其`CONFIG_MBASE`将会被定义成`0x80000000`.     物理内存的编址

CPU访问内存时, 我们会将CPU将要访问的内存地址映射到`pmem`中的相应偏移位置, 这是通过`nemu/src/memory/paddr.c`中的`guest_to_host()`函数实现的.

这个内置的客户程序是一个图像

回到 init_monitor() 

继续调用`load_img()`函数 (在`nemu/src/monitor/monitor.c`中定义). 这个函数会将一个有意义的客户程序从[镜像文件](https://en.wikipedia.org/wiki/Disk_image)读入到内存, 覆盖刚才的内置客户程序. 这个镜像文件是运行NEMU的一个可选参数, 在运行NEMU的命令中指定. 如果运行NEMU的时候没有给出这个参数, NEMU将会运行内置客户程序.



make run之后出现如下信息

/bin/sh: 1: hostnamectl: not found
+ LD /home/xuange/ics2021/nemu/build/riscv32-nemu-interpreter
  /bin/sh: 1: hostnamectl: not found
  /home/xuange/ics2021/nemu/build/riscv32-nemu-interpreter --log=/home/xuange/ics2021/nemu/build/nemu-log.txt
  [src/utils/log.c:13 init_log] Log is written to /home/xuange/ics2021/nemu/build/nemu-log.txt
  [src/memory/paddr.c:36 init_mem] physical memory area [0x80000000, 0x88000000]
  [src/monitor/monitor.c:36 load_img] No image is given. Use the default build-in image.
  [src/monitor/monitor.c:13 welcome] Trace: ON
  [src/monitor/monitor.c:14 welcome] If trace is enabled, a log file will be generated to record the trace. This may lead to a large log file. If it is not necessary, you can disable it in menuconfig
  [src/monitor/monitor.c:17 welcome] Build time: 23:20:59, Jan 19 2023
  Welcome to riscv32-NEMU!
  For help, type "help"
  [src/monitor/monitor.c:20 welcome] Exercise: Please remove me in the source code and compile NEMU again.
  riscv32-nemu-interpreter: src/monitor/monitor.c:21: welcome: Assertion `0' failed.
  make: *** [/home/xuange/ics2021/nemu/scripts/native.mk:23: run] Aborted

  

### 运行第一个客户程序

在初始化monitor之后 main 会继续调用`engine_start()`函数 (在`nemu/src/engine/interpreter/init.c`中定义). 代码会进入简易调试器(Simple Debugger)的主循环`sdb_mainloop()` (在`nemu/src/monitor/sdb/sdb.c`中定义), 并输出NEMU的命令提示符:

这两天重装了wsl和unbantu

重新安装了环境 终于能让nemu正常运行了 --1.25 凌晨1:27

wsl默认不支持systemd

得配置wsl.conj文件  （见官方文档）

而且想正常运行nemu得删除monitor.c中的 assert(0) 语句

为了测试大家是否已经理解框架代码, 我们给大家设置一个练习: 如果在运行NEMU之后直接键入`q`退出, 你会发现终端输出了一些错误信息. 请分析这个错误信息是什么原因造成的, 然后尝试在NEMU中修复它.

make: *** [/home/xuange/ics2021/nemu/scripts/native.mk:23: run] Error 1

这是错误信息

外卖来到 native.mk 第23行

$(NEMU_EXEC) 这里

NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)

$(BINARY): compile_git

IMG ?=



不是.mk文件的问题

问题出现在

~~~c
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INSTR_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

~~~





25号任务 用gdb --》 make gdb 调试nemu

调试发现 每次结束对engine_start的调用

会有个返回值

由is_exit_status_bad() 产生

检测退出的状态

发现直接q结束的话 

该函数临时变量good的值为0

而先按c再按q的 good 的值为1

~~~c
#include <utils.h>

NEMUState nemu_state = { .state = NEMU_STOP };

int is_exit_status_bad() {
  int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||
    (nemu_state.state == NEMU_QUIT);
  return !good;
}
                        
~~~

~~~c
enum { NEMU_RUNNING, NEMU_STOP, NEMU_END, NEMU_ABORT, NEMU_QUIT };//状态码
~~~

int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||
    (nemu_state.state == NEMU_QUIT);

对于这个

发现：

当先按c再按q的 good 的值为1 ---》》 nemu_state.state为2对应**NEMU_END**

而nemu_state.halt_ret为0

直接q结束的话 nemu_state.state为1对应**NEMU_STOP**

而nemu_state.halt_ret还为0

只要在cmd_q 中 加一项将nemu_state.state 设为 NEMU_QUIT 即可



- 存储器是个在`nemu/src/memory/paddr.c`中定义的大数组
- PC和通用寄存器都在`nemu/src/isa/$ISA/include/isa-def.h`中的结构体中定义
- 加法器在... 嗯, 这部分框架代码有点复杂, 不过它并不影响我们对TRM的理解, 我们还是在PA2里面再介绍它吧
- TRM的工作方式通过`cpu_exec()`和`fetch_decode_exec_updatepc()`体现

准备开始完善简易调试器sdb

26号早上简单地阅读了一下

晚上搞



在完善简易调试器

就是写函数

然后对应上结构体给上 命令行字符 说明 函数指针

第一个单步执行很简单 给好了模拟cpu的函数 直接按参数调用即可



第二个是打印寄存器

我以为这是给好了函数调用就行

原来是要自己去写这个isa有关的打印函数代码

搞了在本地windows上vscode 来使用wsl 确实方便



首先是得知道有哪些寄存器 riscv32

首先在isa文件中看看reg.h reg.c

发现有寄存器的名字

还可以用个宏定义

然后是扫描内存



27号晚上看一下riscv手册

很困但睡不着 27号晚上七点继续

要写扫描内存的函数

ics2021/nemu/src/memory/vaddr.c

在这里找到虚拟内存的读取

~~~c
word_t vaddr_read(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}
~~~

在读取过程中总是出错

原来是搞错了strtok的真正用法

基础设施这节还剩下查看单步执行如何打印的

28号晚上开搞



分析了cpu执行怎么打印单步执行的代码的 snprintf

在代码中注释了 应该是在反汇编过程中打印的





## 表达式求值

得先学一点基本的正则表达式语法

2.20号 更新 快一个月在忙课内知识 过几天要继续pa进度了



3.14更新 gui->xserver

3.15重拾pa

表达式求值中要求用正则表达式分别编写用于识别这些token类型的规则

一条规则是由正则表达式和token类型组成的二元组

在sdb中expr.c中

make_token（）有循环来记录匹配token

要完成的内容 

1. 为算数表达式中的token类型添加规则 注意转义字符和正则表达式中元字符的功能

2. 将在成功识别出token后 将token的信息依次记录到`tokens`数组中 注意缓冲区的溢出

3.19今天看了别人思路完成了词法分析 

还没去测试 先测试了 以前完成的 x 和 info 发现居然错了 下午继续弄吧

原来是少了参数 哈哈 但是优化了少了参数的情况---》打印一句话



20号搞递归求值

这部分的内容要在 expr.c中的 expr()内完成

主要是运用递归 从一个长的表达式分成许多子表达式求值

用两个指针指向表达式的开始和结束

判断是否 1. 不合法 2.最简 3.是否含括号

如果上述三种都不满足

那就要找到其 “主表达式”

而后继续分裂

又观摩了一个大神写的代码 弗如远甚

具体细节写在代码里了



下一步是随机生成测试用例

在`nemu/tools/gen-expr/gen-expr.c`中需要实现其中的`void gen_rand_expr()`函数, 将随机生成的表达式输出到缓冲区`buf`中. `main`函数中的代码会调用你实现的`gen_rand_expr()`

3.25调试了一下 算是把表达式求值这部分解决了

接着就是实现监视点了

3.28

用链表实现监视点信息组织

讲义里没写全 不只是要求的两个函数

有一个思路 从cmd_w()的实现开始

要求生成一个监视点



3.29 昨天我一直疑惑的一件事就是 init_wp_pool函数到底初始化了什么

原来在wp_pool数组就是 链表所要用到的空间 在栈上开辟的



当完成了监视点相关的函数后

应该把检测监视点的工作放在	trace_and_difftest()中 

看了网上为数不多的21年的pa 都没有按照要求包装在一个宏里 然后在`nemu/Kconfig`中为监视点添加一个开关选项

对于Kconfig 靠着半蒙半猜 顺利添加了开关选项 和宏定义--》 添加开关回自动生成一个宏 CONFIG_name

name 是添加的开关名字 

然后就是用双引号包含头文件

全都弄好后发现 我参照的github的写的代码实在是不能满足要求 bug太多

于是我在此基础上完善了代码

在测试的时候一定要拿监视点当前的值和过去的值比较 并及时更新

明天再测试一下代码然后继续进行

目前还没有完善两个监视点在同一步中同时改变的问题

3.30 明天开始pa1最后一节

4.2 简单地了解了一下 riscv

PA1最后一节让看了riscv32的知识 理解基础设施 程序是个状态机

然后给一个要完成的shell命令 如何查看代码行数

完成PA1的内容之后，你可以使用以下命令得到nemu/目录下的所有.c和.h和文件总共有多少行代码：

```bash
find nemu/ -name "*.c" -o -name "*.h" | xargs wc -l
```

这个命令会输出所有.c和.h文件的行数总和。在PA1中，你需要编写的代码行数取决于你的实现。如果你想知道你在PA1中编写了多少行代码，可以使用以下命令：

```bash
git diff --shortstat HEAD HEAD~1
```

你可以使用以下命令回到pa0分支中记录的状态：

```bash
git checkout pa0
```

算是完成的PA1 回头看看其实并不难 （代码部分）

难点在于理解讲义文字中表达的信息

要做什么？ 怎么做？



另外 wsl图形化的方法 https://www.davecwright.org/post/wsl-gui/win10-wsl-setup/

https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-vnc-on-ubuntu-20-04



pa2.1中用c模拟出了一个取指译码执行的过程

需要复习一下联合体的知识

4.3 今天弄了半天提交不上github 原来是我开着代理导致提交不上去 明天阅读一下源码

4.5 开始阅读源码 取指译码的过程一边结合cpu的部分 一边结合isa的部分来看

译码辅助函数

译码操作数辅助函数

nemu 把译码看作查表



4.6对于执行过程 通过执行辅助函数来模拟

每个执行辅助函数 都需要有一个标识该指令的ID以及一个表格辅助函数与之相对应

在`nemu/src/isa/$ISA/include/isa-all-instr.h`中定义用于表示指令列表的宏`INSTR_LIST`

, 它定义了NEMU支持的所有指令. 然后代码通过一种类似函数式编程的方式来定义如下相关的内容:

- 在

  ```
  nemu/include/cpu/decode.h
  ```

  中为所有的执行辅助函数定义相应的ID. 以riscv32为例, 对

  ```
  def_all_EXEC_ID()
  ```

  进行宏展开后, 结果如下:

  ```c
  enum { EXEC_ID_lui, EXEC_ID_lw, EXEC_ID_sw, EXEC_ID_inv, EXEC_ID_nemu_trap, TOTAL_INSTR }
  ```

  其中

  ```
  TOTAL_INSTR
  ```

  的值正好为目前所有指令的总数.

- 在`nemu/include/cpu/decode.h`中为所有的执行辅助函数定义相应的表格辅助函数. 这是通过宏`def_all_THelper()`来定义的, 它会为每条指令定义一个表格辅助函数, 用于返回相应的ID.

- 在`nemu/src/cpu/cpu-exec.c`中为所有的执行辅助函数定义`g_exec_table`.

我们只需要维护`nemu/src/isa/$ISA/include/isa-all-instr.h`中的指令列表, 就可以正确维护执行辅助函数和译码之间的关系了.

对于`g_exec_table` 里有一个map 是：

MAP(INSTR_LIST, FILL_EXEC_TABLE)

\#define INSTR_LIST(f) f(lui) f(lw) f(sw) f(inv) f(nemu_trap)

更新过程中

在执行辅助函数中正确维护`s->dnpc`.



实现新指令 要：

1. 在`nemu/src/isa/$ISA/instr/decode.c`中添加正确的模式匹配规则
2. 用RTL实现正确的执行辅助函数, 需要注意使用RTL伪指令时要遵守上文提到的小型调用约定
3. 在`nemu/src/isa/$ISA/include/isa-all-instr.h`中把指令添加到`INSTR_LIST`中
4. 必要时在`nemu/src/isa/$ISA/include/isa-exec.h`中添加相应的头文件
5. 在选择riscv时要多编写一点译码辅助函数和执行辅助函数



明天梳理一下源码 开始敲代码 看一下一生一芯

一生一芯的代码选讲是2022年的pa 代码与2021的不同

但也搞懂了makefile中加GCC -E选项



## 请整理一条指令在NEMU中的执行过程.

在

`cpu_exec(uint64_t n)`

先会调用 `fetch_decode_exec_updatepc(&s);`

进入取值 译码 执行 更新pc 的总函数

接着会调用 

`fetch_decode(s, cpu.pc);` 进行取指和译码

先更新下条pc可能会执行的地址 s->snpc = pc;

## 取指

然后调用具体 isa 的取指译码函数` int isa_fetch_decode(Decode *s)`

`isa_fetch_decode()`还会返回一个编号`idx`, 用于对`g_exec_table`这一数组进行索引.

`g_exec_table`是一个函数指针的数组, 数组中的每个元素都会指向一个用于模拟指令执行的函数, 我们把这样的函数称为"执行辅助函数"(execution helper function). 通过`idx`索引这个数组, 可以找到与一条指令相匹配的执行辅助函数, 并把它记录到`s->EHelper`中.

`isa_fetch_decode()` 

调用： `s->isa.instr.val = instr_fetch(&s->snpc, 4);` 

会从内存中读取指令（作为返回值 返回 留着查表用） 然后更新传入的pc

## 译码

指令记录到`s->isa.instr.val`中

然后在 `isa_fetch_decode()`查表：

调用：` int idx = table_main(s);`

这个`idx` 就是含函数的返回值 用于执行辅助

会用各种宏和

译码辅助函数

译码操作数辅助函数

来辅助译码

表格辅助函数`table_lui()`做的事情很简单, 它直接返回一个标识`lui`指令的唯一ID. 

这个ID会作为译码结果的返回值, 在`fetch_decode()`中索引`g_exec_table`数组.

事实上, NEMU把译码时的如下情况都看作是查表过程:

- 在`isa_fetch_decode()`中查主表(main decode table)
- 在译码过程中分别匹配指令中的每一个域(如上文介绍的`table_load()`
- 译码出最终的指令时认为是一种特殊的查表操作, 直接返回标识该指令的唯一ID

如果所有模式匹配规则都无法成功匹配, 代码将会返回一个标识非法指令的ID.

## 执行

译码过程结束之后, 接下来会返回到`fetch_decode()`中, 并通过返回的ID来从`g_exec_table`数组中选择相应的执行辅助函数(execution helper function), 然后记录到`s->EHelper`中.

然后在`fetch_decode_exec_updatepc`调用

最后在`fetch_decode_exec_updatepc`更新动态pc



## 执行辅助函数

统一通过宏`def_EHelper`(在`nemu/include/cpu/exec.h`中定义)来定义:

执行辅助函数通过RTL指令来描述指令真正的执行功能

每个执行辅助函数都需要有一个标识该指令的ID以及一个表格辅助函数与之相对应, 这一点是通过一系列宏定义来实现的. 在`nemu/src/isa/$ISA/include/isa-all-instr.h`中定义用于表示指令列表的宏`INSTR_LIST`, 它定义了NEMU支持的所有指令. 然后代码通过一种类似函数式编程的方式来定义如下相关的内容:

## 更新pc

更新PC的操作非常简单, 只需要把`s->dnpc`赋值给`cpu.pc`即可. 我们之前提到了`snpc`和`dnpc`。



## TODO

我们只需要维护`nemu/src/isa/$ISA/include/isa-all-instr.h`中的指令列表, 就可以正确维护执行辅助函数和译码之间的关系了.

实现RTL伪指令 在`nemu/include/rtl/pseudo.h` ISA无关的RTL伪指令

对于RISC v  no isa-dependent rtl instructions

### 实现新指令

1. 在`nemu/src/isa/$ISA/instr/decode.c`中添加正确的模式匹配规则
2. 用RTL实现正确的执行辅助函数, 需要注意使用RTL伪指令时要遵守上文提到的小型调用约定
3. 在`nemu/src/isa/$ISA/include/isa-all-instr.h`中把指令添加到`INSTR_LIST`中
4. 必要时在`nemu/src/isa/$ISA/include/isa-exec.h`中添加相应的头文件



编译dummy 程序

```bash
make ARCH=riscv32-nemu ALL=dummy run
```

缺少指令自然是运行不了的



查询反汇编：

~~~apl
80000000 <_start>:
80000000:	00000413          	li	s0,0
80000004:	00009117          	auipc	sp,0x9
80000008:	ffc10113          	addi	sp,sp,-4 # 80009000 <_end>
8000000c:	00c000ef          	jal	ra,80000018 <_trm_init>

80000010 <main>:
80000010:	00000513          	li	a0,0
80000014:	00008067          	ret

80000018 <_trm_init>:
80000018:	80000537          	lui	a0,0x80000
8000001c:	ff010113          	addi	sp,sp,-16
80000020:	03850513          	addi	a0,a0,56 # 80000038 <_end+0xffff7038>
80000024:	00112623          	sw	ra,12(sp)
80000028:	fe9ff0ef          	jal	ra,80000010 <main>
8000002c:	00050513          	mv	a0,a0
80000030:	0000006b          	0x6b
80000034:	0000006f          	j	80000034 <_trm_init+0x1c>
~~~
