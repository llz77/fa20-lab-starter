#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n)
{
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns
    // 0 or 1)
    // 右移动n位，然后与1取AND
    x = x >> n;
    return x & 1;
}

// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned *x,
             unsigned n,
             unsigned v)
{
    // YOUR CODE HERE
    // 由于只改变第n位，所以x不移动

    unsigned mask = ~(1 << n);
    *x = *x & mask;
    unsigned target = v << n;
    *x = *x | target;
}

// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned *x,
              unsigned n)
{
    // YOUR CODE HERE
    // 单个1去做移位就正确了
    unsigned mask = 1 << n;
    *x = *x ^ mask;
}
