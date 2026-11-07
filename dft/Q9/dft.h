#include <ap_int.h>

#ifndef DFT_H
#define DFT_H

#include <ap_axi_sdata.h>
#include <hls_stream.h>


typedef float DTYPE;

#define SIZE 1024 		/* SIZE OF DFT */

// void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE],DTYPE real_op[SIZE], DTYPE imag_op[SIZE]);
// Use streaming interface for demo

// void axis_fp_example(
//      hls::stream<transPkt>&A,
//      hls::stream<transPkt>&B,
//      hls::stream<transPkt>&C,
//      hls::stream<transPkt>&D
// );

// user defined type
// 64-bit AXI-stream sizes:
// bits [31:0]  = real float
// bits [63:32] = imaginary float
typedef ap_axiu<32, 0, 0, 0> axis_float_t;

void dft(
    // A stream declaration
    hls::stream<axis_float_t> &real_input_stream,
    hls::stream<axis_float_t> &imag_input_stream,
    hls::stream<axis_float_t> &real_output_stream,
    hls::stream<axis_float_t> &imag_output_stream
);

#endif
