#ifndef CORDICCART2POL_H
#define CORDICCART2POL_H

#define NO_ITER 16
#include <ap_fixed.h>

typedef unsigned char iter_t;
// typedef int   coef_t;
// typedef float data_t;
// typedef float acc_t;

// ap_fixed<16,3>
// 16 total bits, 3 int bits, 13 fractional
// ap_fixed<Total Bits = Int Bits + Fractional Bits, Int Bits>
typedef int   coef_t;
typedef float acc_t;
typedef ap_fixed<16,3> data_t;

// 4
// typedef ap_fixed<4,3> kvalues_t;
// typedef ap_fixed<4,3> angles_t;

// 8
// typedef ap_fixed<8,3> kvalues_t;
// typedef ap_fixed<8,3> angles_t;

// 12
// typedef ap_fixed<12,3> kvalues_t;
// typedef ap_fixed<12,3> angles_t;

// 16
// typedef ap_fixed<16,3> kvalues_t;
// typedef ap_fixed<16,3> angles_t;

// 20
// typedef ap_fixed<20,3> kvalues_t;
// typedef ap_fixed<20,3> angles_t;

// 32
typedef ap_fixed<32,3> kvalues_t;
typedef ap_fixed<32,3> angles_t;

void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta);

#endif
