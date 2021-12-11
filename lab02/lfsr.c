#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    // 0, 2, 3, 5做异或，然后取出最后一位
    uint16_t bit = ((*reg) ^ (*reg >> 2) ^ (*reg >> 3) ^ (*reg >> 5)) & 1;
    // reg右移动1位
    *reg = *reg >> 1;
    // bit左移15位，做或，去覆盖reg的第15位
    *reg = *reg | (bit << 15);
}

