/*
 * Helpers for floating-point tests.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */
#ifndef FLOAT_H
#define FLOAT_H

/*
 * Floating-point value classes.
 */
#define N_FORMATS 3
#define CLASS_MINUS_INF 0
#define CLASS_MINUS_FN 1
#define CLASS_MINUS_ZERO 2
#define CLASS_PLUS_ZERO 3
#define CLASS_PLUS_FN 4
#define CLASS_PLUS_INF 5
#define CLASS_QNAN 6
#define CLASS_SNAN 7
#define N_SIGNED_CLASSES 8
static const size_t float_sizes[N_FORMATS] = {
    /* M4 == 2: short    */ 4,
    /* M4 == 3: long     */ 8,
    /* M4 == 4: extended */ 16,
};
static const size_t e_bits[N_FORMATS] = {
    /* M4 == 2: short    */ 8,
    /* M4 == 3: long     */ 11,
    /* M4 == 4: extended */ 15,
};
struct float_class {
    size_t n;
    unsigned char v[2][16];
};
static const struct float_class signed_floats[N_FORMATS][N_SIGNED_CLASSES] = {
    /* M4 == 2: short */
    {
        /* -inf */ {1, {{0xff, 0x80, 0x00, 0x00}}},
        /* -Fn */  {2, {{0xc2, 0x28, 0x00, 0x00},
                        {0xc2, 0x29, 0x00, 0x00}}},
        /* -0 */   {1, {{0x80, 0x00, 0x00, 0x00}}},
        /* +0 */   {1, {{0x00, 0x00, 0x00, 0x00}}},
        /* +Fn */  {2, {{0x42, 0x28, 0x00, 0x00},
                        {0x42, 0x2a, 0x00, 0x00}}},
        /* +inf */ {1, {{0x7f, 0x80, 0x00, 0x00}}},
        /* QNaN */ {2, {{0x7f, 0xff, 0xff, 0xff},
                        {0x7f, 0xff, 0xff, 0xfe}}},
        /* SNaN */ {2, {{0x7f, 0xbf, 0xff, 0xff},
                        {0x7f, 0xbf, 0xff, 0xfd}}},
    },

    /* M4 == 3: long */
    {
        /* -inf */ {1, {{0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* -Fn */  {2, {{0xc0, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                        {0xc0, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* -0 */   {1, {{0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* +0 */   {1, {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* +Fn */  {2, {{0x40, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                        {0x40, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* +inf */ {1, {{0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* QNaN */ {2, {{0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
                        {0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe}}},
        /* SNaN */ {2, {{0x7f, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
                        {0x7f, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd}}},
    },

    /* M4 == 4: extended */
    {
        /* -inf */ {1, {{0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* -Fn */  {2, {{0xc0, 0x04, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                        {0xc0, 0x04, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* -0 */   {1, {{0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* +0 */   {1, {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* +Fn */  {2, {{0x40, 0x04, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                        {0x40, 0x04, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* +inf */ {1, {{0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
        /* QNaN */ {2, {{0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
                        {0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe}}},
        /* SNaN */ {2, {{0x7f, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
                        {0x7f, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd}}},
    },
};
static const unsigned char default_nans[N_FORMATS][16] = {
    /* M4 == 2: short    */ {0x7f, 0xc0, 0x00, 0x00},
    /* M4 == 3: long     */ {0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    /* M4 == 4: extended */ {0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
};

static void dump_v(FILE *f, const void *v, size_t n)
{
    for (int i = 0; i < n; i++) {
        fprintf(f, "%02x", ((const unsigned char *)v)[i]);
    }
}

static void snan_to_qnan(char *v, int fmt)
{
    size_t bit = 1 + e_bits[fmt];
    v[bit / 8] |= 1 << (7 - (bit % 8));
}

#endif