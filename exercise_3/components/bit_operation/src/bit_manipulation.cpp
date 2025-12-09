#include "bit_manipulation.hpp"

unsigned int set_bit(unsigned int value, unsigned int bit) {
    return value | (1U << bit);
}

unsigned int clear_bit(unsigned int value, unsigned int bit) {
    return value & ~(1U << bit);
}

unsigned int toggle_bit(unsigned int value, unsigned int bit) {
    return value ^ (1U << bit);
}

unsigned int extract_bits(unsigned int value, unsigned int pos, unsigned int count) {
    return (value >> pos) & ((1U << count) - 1U);
}

unsigned int count_bits_set(unsigned int value) {
    unsigned int count = 0;
    while (value) {
        count += value & 1U;
        value >>= 1;
    }
    return count;
}

unsigned int reverse_bits(unsigned int value) {
    unsigned int rev = 0;
    for (int i = 0; i < sizeof(unsigned int) * 8; i++) {
        rev <<= 1;
        rev |= (value & 1U);
        value >>= 1;
    }
    return rev;
}

unsigned int rotate_left(unsigned int value, unsigned int n) {
    unsigned int bits = sizeof(unsigned int) * 8;
    n %= bits;
    return (value << n) | (value >> (bits - n));
}

unsigned int rotate_right(unsigned int value, unsigned int n) {
    unsigned int bits = sizeof(unsigned int) * 8;
    n %= bits;
    return (value >> n) | (value << (bits - n));
}
