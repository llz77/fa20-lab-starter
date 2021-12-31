## Lab03

#### ex1 fib的汇编代码

```
.data
.word 2, 4, 6, 8
n: .word 9

.text
main:
    add t0, x0, x0
    addi t1, x0, 1
    la t3, n
    lw t3, 0(t3)
fib:
    beq t3, x0, finish
    add t2, t1, t0
    mv t0, t1
    mv t1, t2
    addi t3, t3, -1
    j fib
finish:
    addi a0, x0, 1
    addi a1, t0, 0
    ecall # print integer ecall
    addi a0, x0, 10
    ecall # terminate ecall
```

#### ex2 从c转换到RISC-V

带数组的，数组到数组执行一个函数过程

关注汇编文件的布局 .global	.data	source	dest	.text

#### ex3 阶乘

```
.globl factorial

.data

n: .word 8

.text

main:

  la t0, n
  lw a0, 0(t0)
  jal ra, factorial

  addi a1, a0, 0
  addi a0, x0, 1
  ecall # Print Result

  addi a1, x0, *'\n'*
  addi a0, x0, 11
  ecall # Print newline

  addi a0, x0, 10
  ecall # Exit

factorial:

  \# YOUR CODE HERE
  li t0, 1
  beq a0, t0, finish
  addi sp, sp, -8
  sw ra, 4(sp)    #push ra
  sw a0, 0(sp)    #push a0
  addi a0, a0, -1   #ao = ao - 1
  jal ra, factorial
  lw t0, 0(sp)
  mul a0, a0, t0
  lw ra, 4(sp)
  addi sp, sp, 8
  
finish:
  ret
```

#### ex4 约定检查器

​	所有覆盖按约定保留的寄存器的函数都必须有一个序言，它在函数开始时将这些寄存器值保存到堆栈中，以及一个尾声，它为函数的调用者恢复这些值。

```bash
java -jar tools/venus.jar -cc lab03/cc_test.s
```
