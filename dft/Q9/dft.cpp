#include<math.h>
#include "dft.h"
#include "coefficients1024.h"

// Convert raw 32-bit AXI data to float
static DTYPE bits_to_float(ap_uint<32> bits)
{
    union {
        unsigned int uint_value;
        float float_value;
    } converter;

    converter.uint_value = (unsigned int)bits;
    return converter.float_value;
}

// Convert float to raw 32-bit AXI data
static ap_uint<32> float_to_bits(DTYPE value)
{
    union {
        unsigned int uint_value;
        float float_value;
    } converter;

    converter.float_value = value;
    return converter.uint_value;
}

// void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE],DTYPE real_op[SIZE],DTYPE imag_op[SIZE])	//Use pointers while doing the demo for streaming//
// {
//Write your code here
void dft(
    // pointers for demo streaming
    hls::stream<axis_float_t> &real_input_stream,
    hls::stream<axis_float_t> &imag_input_stream,
    hls::stream<axis_float_t> &real_output_stream,
    hls::stream<axis_float_t> &imag_output_stream
)
{

// AXI stream interface pragmas for input and output ports
#pragma HLS INTERFACE mode=axis port=real_input_stream
#pragma HLS INTERFACE mode=axis port=imag_input_stream
#pragma HLS INTERFACE mode=axis port=real_output_stream
#pragma HLS INTERFACE mode=axis port=imag_output_stream

// AXI Lite interface pragma for control signals
#pragma HLS INTERFACE mode=s_axilite port=return bundle=control

// int i, j;
int i;
int j;

// Data type for the temporary variables
// TEMP TYPE w;
// TEMP TYPE c, s;
// DTYPE w;
// DTYPE c;
// DTYPE s;
// double w;
// double c;
// double s;

// #pragma HLS INTERFACE axis port=input_stream
// #pragma HLS INTERFACE axis port=output_stream

// arrays for internal accumulated DFT results
double temp_real[SIZE];
double temp_imag[SIZE];

// const double PI = 3.141592653589;

// Initialize accumulator arrays to 0 with full pipelining
// Calculate each frequency domain sample iteratively
// for (i = 0; i < N; i += 1) {
for (i = 0; i < SIZE; i++) 
{
#pragma HLS PIPELINE II=1

        // temp real[i] = 0;
        // DTYPE temp_real = 0.0f;
        temp_real[i] = 0.0;

        // temp imag[i] = 0;
        // DTYPE temp_imag = 0.0f;
        temp_imag[i] = 0.0;
    }

    // // (2 ∗ pi ∗ i)/N
    // w = (2.0 ∗ 3.141592653589 / N) ∗ (TEMP TYPE)i;
    // w = (2.0*3.141592653589/SIZE)*(DTYPE)i;
    // w = (2.0*PI/(double)SIZE)*(double)i;

    // process input data sample and update frequency bins
    // Calculate the jth frequency sample sequentially
// for (i = 0; i < N; i += 1) {
    for (j = 0; j < SIZE; j++) 
    {
        axis_float_t real_input_word = real_input_stream.read();
        axis_float_t imag_input_word = imag_input_stream.read();
        
        // Convert input data to double precision
        double input_real = (double)bits_to_float(real_input_word.data);
        double input_imag = (double)bits_to_float(imag_input_word.data);

        // Utilize HLS tool to calculate sine and cosine values
        // c = cos(j ∗ w);
        // c = cos(j*w);
        // double c = cos((double)j*w);
        
        // s = −sin(j ∗ w);
        // s = -sin(j*w);
        // double s = -sin((double)j*w);

    // Update all frequency bins with the current input sample
    for (i = 0; i < SIZE; i++) 
    {
#pragma HLS PIPELINE II=1
#pragma HLS UNROLL factor=3
        // table index wrapping around 1024 size
        int lut_index = (i * j) & (SIZE - 1);
        // LUT lookup for sine and cosine coefficients
        double c = (double)cos_coefficients_table[lut_index];
        double s = (double)sin_coefficients_table[lut_index];

        // Multiply the current phasor with the appropriate input sample and keep
        // running sum
        // temp real[i] += (sample real[j] ∗ c − sample imag[j] ∗ s);
        // temp_real += (real_sample[j]*c - imag_sample[j]*s);
        // temp_real += ((double)real_sample[j]*c - (double)imag_sample[j]*s);
        // real_op[i] += ((double)real_sample[j]*c - (double)imag_sample[j]*s);
        temp_real[i] += (input_real*c - input_imag*s);
        
        // temp imag[i] += (sample real[j] ∗ s + sample imag[j] ∗ c);
        // temp_imag += (real_sample[j]*s + imag_sample[j]*c);
        // temp_imag += ((double)real_sample[j]*s + (double)imag_sample[j]*c);
        // imag_op[i] += ((double)real_sample[j]*s + (double)imag_sample[j]*c);
        temp_imag[i] += (input_real*s + input_imag*c);


    }
    }

// Q1 and Q2
// Perform an inplace DFT, i.e., copy result into the input arrays
// for (i = 0; i < N; i += 1) {
for( i = 0; i < SIZE; i++)
    {
#pragma HLS PIPELINE II=1
        // Convert accumulated DFT results to output stream words
        axis_float_t real_output_word;
        axis_float_t imag_output_word;

        // sample real[i] = temp real[i];
        // real_op[i] = temp_real;
        // real_op[i] = (DTYPE)temp_real[i];
        real_output_word.data = float_to_bits((DTYPE)temp_real[i]);

        // sample imag[i] = temp imag[i];
        // imag_op[i] = temp_imag;
        // imag_op[i] = (DTYPE)temp_imag[i];
        imag_output_word.data = float_to_bits((DTYPE)temp_imag[i]);

        // All eight byte lanes contain valid data
        real_output_word.keep = -1;
        real_output_word.strb = -1;
        imag_output_word.keep = -1;
        imag_output_word.strb = -1;

        // Assert TLAST on the final DFT output
        real_output_word.last = (i == SIZE - 1);
        imag_output_word.last = (i == SIZE - 1);

        // Write output words to the output streams
        real_output_stream.write(real_output_word);
        imag_output_stream.write(imag_output_word);
}


}
