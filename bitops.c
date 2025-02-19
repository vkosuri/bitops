/*
 * bitops.c
 * 
 * Copyright (c) 2024 vkosuri <malli.kv2@gmail.com>
 * 
 * License: MIT LICENSE, see file in root directory
 */

#include "bitops.h"
#include <stdio.h>
#include <string.h>

uint8_t set_bit(uint8_t x, uint8_t p)
{
    return (x | (1 << p));
}

uint8_t clear_bit(uint8_t x, uint8_t p)
{
    return (x & ~(1 << p));
}

uint8_t toggle_bit(uint8_t x, uint8_t p)
{
    return (x ^ (1 << p));
}

uint8_t get_bit_status(uint8_t x, uint8_t p)
{
    return ((x >> p) & 1);
}

uint8_t is_even(uint8_t x)
{
    return !(x & 1);
}

char* format_binary(uint8_t x)
{
    static char res[9];
    for (int i = 7; i >= 0; i--) {
        res[7 - i] = (x & (1 << i)) ? '1' : '0';
    }
    res[8] = '\0';
    return res;
}

uint8_t count_set_bits(uint8_t x)
{
    uint8_t count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

uint8_t is_power_of_2(uint8_t x)
{
    return x && !(x & (x - 1));
}

int8_t subtract(int8_t x, int8_t y)
{
    while (y != 0) {
        int8_t borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}

int8_t add(int8_t x, int8_t y)
{
    while (y != 0) {
        int8_t carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

uint8_t xor_without_operator(uint8_t x, uint8_t y)
{
    return (x | y) & (~x | ~y);
}

uint8_t size_of_using_bitwise()
{
    uint8_t size = 0;
    uint8_t x = 1;
    while (x) {
        x <<= 1;
        size++;
    }
    return size / 8;
}

uint32_t little_to_big_endian(uint32_t x)
{
    return ((x & 0xFF000000) >> 24) |
           ((x & 0x00FF0000) >> 8) |
           ((x & 0x0000FF00) << 8) |
           ((x & 0x000000FF) << 24);
}

uint8_t multiply_by_n(uint8_t x, uint8_t n) 
{
    uint8_t result = 0;
    uint8_t multiplier = x;

    /* Iterate through the bits of n */
    for (int i = 0; i < 8; ++i) {
        if (n & (1 << i)) {
            /* If the i-th bit of n is set, add the current multiplier to the result */
            result += multiplier;
        }
        /* Update the multiplier by left-shifting it by 1 */
        multiplier <<= 1;
    }

    return result;
}


uint8_t is_nth_bit_on(uint32_t x, uint8_t n) 
{
    uint8_t mask = 1 << n;
    return (x & mask) != 0;
}

uint8_t set_bits(uint8_t x, uint8_t p, uint8_t n, uint8_t y) 
{
    uint8_t mask = (1 << n) - 1;
    y = (y & mask) << (p - n + 1);
    mask = ~(mask << (p - n + 1));
    return (x & mask) | y;
}

void swap(uint8_t *x, uint8_t *y) 
{
    if (x != y) {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

uint8_t clear_lsb(uint8_t x) 
{
    return x & (x - 1);
}

uint8_t find_msb(uint8_t x) 
{
    uint8_t msb = 0;
    while (x != 0) {
        x >>= 1;
        msb++;
    }
    return msb;
}

uint8_t swap_nibbles(uint8_t x) 
{
    return ((x & 0x0F) << 4) | ((x & 0xF0) >> 4);
}