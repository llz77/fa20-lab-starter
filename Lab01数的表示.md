## Lab01

#### ex1

eccentrics，基本的gcc用法，c语言switch语句的控制流程，#define基本用法

#### ex2

gdb基本用法，参阅gdb card，注意finish

#### ex3

gdb中run的是否，加上< 文件名 可以实现传递参数

#### ex4

泄露检查，valgrind

```bash
$ valgrind ./segfault_ex
```

#### ex5

快慢指针，核心是双指针怎么往后移，边移边判断，传入的是链表节点的指针，重新声明slow, fast变量时也都用的是一样的

```c
if (head == NULL)
  {
    return 0;
  }
  node *slow, *fast;
  slow = fast = head;
  while (1)
  {
	fast = fast->next;
    if (fast == NULL)
    {
      return 0;
    }
    fast = fast->next;
    if (fast == NULL)
   {
      return 0;
    }
    slow = slow->next;
    if (slow == fast)
    {
      return 1;
    }
  }
  return 0;
```

