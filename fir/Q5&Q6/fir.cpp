/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.
		Match filter
	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"


void fir (
  data_t *y,
  data_t x
  )
{

	coef_t c[N] = {10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	
	// Write your code here

	static
		data_t shift_reg[N];
		acc_t acc;
		ap_int<8> i;

// #pragma HLS pipeline off
//#pragma HLS PIPELINE II=1
// from textbook Chapter 2.8 Loop Unrolling - pagee 41-42
// #pragma HLS ARRAY_PARTITION variable=shift_reg complete dim=1
#pragma HLS array_reshape variable=shift_reg block factor=2
// #pragma HLS array_reshape variable=shift_reg block factor=4
// #pragma HLS array_partition variable=shift_reg cycle factor=2 dim=1
// #pragma HLS ARRAY_PARTITION variable=shift_reg complete dim=1

// acc = 0;
	TDL :
	// from textbook Chapter 2.6: Code Hoisting - page 39
	for (i = N - 1; i >= 0; i--){
#pragma HLS PIPELINE II=1
#pragma HLS unroll factor=2
		shift_reg[i] = shift_reg[i - 1];
	}
	shift_reg[0] = x;
	
	acc = 0;
	MAC:
	for (i = N - 1; i >= 0; i--){
#pragma HLS PIPELINE II=1
#pragma HLS unroll factor=2
			acc += shift_reg[i] * c[i];
		}				
			
	*y = acc;

}

