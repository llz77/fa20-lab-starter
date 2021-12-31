#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg)
{
    /* YOUR CODE HERE */
    // 0, 2, 3, 5做异或，然后取出最后一位

    unsigned bit = ((*reg) ^ (*reg >> 2) ^ (*reg >> 3) ^ (*reg >> 5)) & 1;

    *reg = *reg >> 1;
    *reg = *reg | (bit << 15);
}
