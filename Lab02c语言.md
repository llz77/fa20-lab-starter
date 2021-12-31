## Lab02

#### ex0 Makefile的基本规则

```makefile
赋值 ：=
指令执行替换  $(shell uname -s)
CC CFLAGS
clean
ifeq ($(UNAME_S), Linux)
    MEMCHECK=valgrind --tool=memcheck --leak-check=full --track-origins=yes
endif
```

#### ex1 位操作

移位>>  <<， 掩码 &， 给值|， ^异或实现反转

#### ex2 线性反馈移位寄存器

按描述逐一操作就可以了

```c
unsigned bit = ((**reg*) ^ (**reg* >> 2) ^ (**reg* >> 3) ^ (**reg* >> 5)) & 1;
*reg = *reg >> 1;
*reg = *reg | (bit << 15);
```

#### ex3 vector-test

valgrind的执行范式

```bash
valgrind --tool=memcheck --leak-check=full --track-origins=yes [OS SPECIFIC ARGS] ./<executable>
```

