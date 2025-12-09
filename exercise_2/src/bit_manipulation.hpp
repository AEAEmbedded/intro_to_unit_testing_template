/**
 * \file            bit_manipulation.h
 * \brief           Useful macros and functions for bit manipulation.
 */
#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#ifdef __cplusplus
extern "C" {
#endif

/* ----- MACROS ----------------------------------------------------------- */

/* Basic bitmask operations */
#define BITMASK_COMPARE(NUM, MASK)           ((NUM) & (MASK))
#define BIT_IS_SET(VAL, BIT_NUM)             (((VAL) >> (BIT_NUM)) & 1U)
#define SHIFT_ONE_LEFT_BY_N(N)               (1U << (N))

/* Nibble extraction (4-bit groups) */
#define GET_LOWER_4_BITS_OF_BYTE(x)          BITMASK_COMPARE((x), 0x0F)
#define GET_UPPER_4_BITS_OF_BYTE(x)          BITMASK_COMPARE((x) >> 4, 0x0F)

/* Even/odd check */
#define PIN_IS_EVEN_NUMBER(x)                (((x) % 2) == 0)

/* Set, clear, toggle single bits */
#define BIT_SET(value, bit)                  ((value) |=  (1U << (bit)))
#define BIT_CLEAR(value, bit)                ((value) &= ~(1U << (bit)))
#define BIT_TOGGLE(value, bit)               ((value) ^=  (1U << (bit)))

/* Create a mask for n bits */
#define MASK_N_BITS(n)                       ((1U << (n)) - 1U)

/* Extract n bits starting at position p (p = LSB index) */
#define EXTRACT_BITS(value, p, n)            (((value) >> (p)) & MASK_N_BITS(n))

/* Replace n bits starting at p with 'bits' */
#define REPLACE_BITS(value, p, n, bits)      \
    (((value) & ~(MASK_N_BITS(n) << (p))) | (((bits) & MASK_N_BITS(n)) << (p)))

/* ----- FUNCTION PROTOTYPES ---------------------------------------------- */

/**
 * @brief Set a specific bit and return the new value.
 */
unsigned int set_bit(unsigned int value, unsigned int bit);

/**
 * @brief Clear a specific bit and return the new value.
 */
unsigned int clear_bit(unsigned int value, unsigned int bit);

/**
 * @brief Toggle a specific bit and return the new value.
 */
unsigned int toggle_bit(unsigned int value, unsigned int bit);

/**
 * @brief Extract n bits starting from position p.
 */
unsigned int extract_bits(unsigned int value, unsigned int pos, unsigned int count);

/**
 * @brief Count number of bits set to 1 (population count).
 */
unsigned int count_bits_set(unsigned int value);

/**
 * @brief Reverse the bit order (e.g. 0b00001101 → 0b10110000).
 */
unsigned int reverse_bits(unsigned int value);

/**
 * @brief Rotate bits left by n positions (circular shift).
 */
unsigned int rotate_left(unsigned int value, unsigned int n);

/**
 * @brief Rotate bits right by n positions (circular shift).
 */
unsigned int rotate_right(unsigned int value, unsigned int n);

#ifdef __cplusplus
}
#endif

#endif /* BIT_MANIPULATION_H */
