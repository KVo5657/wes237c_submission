/*
This is traditional 2-radix DIT FFT algorithm implementation.
INPUT:
	In_R, In_I[]: Real and Imag parts of Complex signal

OUTPUT:
	Out_R, Out_I[]: Real and Imag parts of Complex signal
*/

#include "fft.h"

//void bit_reverse(DTYPE X_R[SIZE], DTYPE X_I[SIZE]);
void bit_reverse(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE Temp_R[SIZE], DTYPE Temp_I[SIZE]);
void fft_stage_first(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]);
void fft_stages(DTYPE X_R[SIZE], DTYPE X_I[SIZE], int STAGES, DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]);
void fft_stage_last(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]);


void fft(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE])
{
#pragma HLS DATAFLOW
#pragma HLS INTERFACE s_axilite port=X_I bundle=FFT
#pragma HLS INTERFACE s_axilite port=X_R bundle=FFT

// real and imaginary ports AXI-lite
#pragma HLS INTERFACE m_axi depth=SIZE port=X_I offset=slave bundle=input_i
#pragma HLS INTERFACE m_axi depth=SIZE port=X_R offset=slave bundle=input_r

// addresses for output buffers
#pragma HLS INTERFACE s_axilite port=OUT_I bundle=FFT
#pragma HLS INTERFACE s_axilite port=OUT_R bundle=FFT

// separate output ports for data to be written to
#pragma HLS INTERFACE m_axi depth=SIZE port=OUT_I offset=slave bundle=output_i
#pragma HLS INTERFACE m_axi depth=SIZE port=OUT_R offset=slave bundle=output_r

// control interface
#pragma HLS INTERFACE s_axilite port=return bundle=FFT

	// initialize temporary arrays
	DTYPE Temp_R[SIZE], Temp_I[SIZE];

	// input data arranged in bit-reversed order
	// bit_reverse(X_R, X_I);
	bit_reverse(X_R, X_I, Temp_R, Temp_I);

	//Call fft
	DTYPE Stage1_R[SIZE], Stage1_I[SIZE];
	DTYPE Stage2_R[SIZE], Stage2_I[SIZE];
	DTYPE Stage3_R[SIZE], Stage3_I[SIZE];
	DTYPE Stage4_R[SIZE], Stage4_I[SIZE];
	DTYPE Stage5_R[SIZE], Stage5_I[SIZE];
	DTYPE Stage6_R[SIZE], Stage6_I[SIZE];
	DTYPE Stage7_R[SIZE], Stage7_I[SIZE];
	DTYPE Stage8_R[SIZE], Stage8_I[SIZE];
	DTYPE Stage9_R[SIZE], Stage9_I[SIZE];

	// fft_stage_first(X_R, X_I, Stage1_R, Stage1_I);
	fft_stage_first(Temp_R, Temp_I, Stage1_R, Stage1_I);
	fft_stages(Stage1_R, Stage1_I, 2, Stage2_R, Stage2_I);
	fft_stages(Stage2_R, Stage2_I, 3, Stage3_R, Stage3_I);
	fft_stages(Stage3_R, Stage3_I, 4, Stage4_R, Stage4_I);
	fft_stages(Stage4_R, Stage4_I, 5, Stage5_R, Stage5_I);
	fft_stages(Stage5_R, Stage5_I, 6, Stage6_R, Stage6_I);
	fft_stages(Stage6_R, Stage6_I, 7, Stage7_R, Stage7_I);
	fft_stages(Stage7_R, Stage7_I, 8, Stage8_R, Stage8_I);
	fft_stages(Stage8_R, Stage8_I, 9, Stage9_R, Stage9_I);
	fft_stage_last(Stage9_R, Stage9_I, OUT_R, OUT_I);

}

// unsigned int reverse bits(unsigned int input) {
unsigned int reverse_address_bits(unsigned int add_in)
{
	// loop counter for each bit
	unsigned int i;
	// loop counter for reversed bits
	unsigned int reverse_add_bits = 0;
// int i, rev = 0;
// for (i = 0; i < M; i++) {
	for(i = 0; i < M; i++) {
// #pragma HLS UNROLL
#pragma HLS LOOP_TRIPCOUNT min=10 max=10
		// rev = (rev << 1) | (input & 1);
		reverse_add_bits = (reverse_add_bits << 1) | (add_in & 1);
		// input = input >> 1;
		add_in = add_in >> 1;
	}

	// return rev;
	return reverse_add_bits;
}

// void bit_reverse(DTYPE X_R[SIZE], DTYPE X_I[SIZE]){
void bit_reverse(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE Temp_R[SIZE], DTYPE Temp_I[SIZE]) {
	//Insert your code here
	//Write your code here.
// #pragma HLS ARRAY_PARTITION variable=X_I cyclic factor=8 dim=1
// #pragma HLS ARRAY_PARTITION variable=X_R cyclic factor=8 dim=1
// unsigned int reversed;

	// bit-reversed index
	unsigned int reverse_add_bits;
	// index of data processed
	unsigned int i;

    // DTYPE x_r_tmp[SIZE];
    // DTYPE x_i_tmp[SIZE];

	// process data loop
	// for (i = 0; i < SIZE; i++) {
	for(i = 0; i < SIZE; i++)
	{
//#pragma HLS PIPELINE
// #pragma HLS UNROLL factor=8
#pragma HLS UNROLL factor=4
#pragma HLS LOOP_TRIPCOUNT min=1024 max=1024
		// calculate bit reversed address
		// reversed = reverse bits(i); // Find the bit reversed index
		reverse_add_bits = reverse_address_bits(i);

		// copy data to temporary arrays
		Temp_R[i] = X_R[reverse_add_bits];
		Temp_I[i] = X_I[reverse_add_bits];

	}


// 	for(i = 0; i < SIZE; i++)
// 	{
//		// if (i <= reversed) {
//		// if(i < reverse_add_bits)
// #pragma HLS UNROLL factor=8
// 			// temp = X R[i];
//			//temp = X_R[i];
//			// X_R[i] = X_R[reverse_add_bits];
//			// X_R[reverse_add_bits] = temp;
//			X_R[i] = Temp_R[i];

//			// temp = X I[i];
//			// temp = X_I[i];
//			// X_I[i] = X_I[reverse_add_bits];
// 			// X_I[reverse_add_bits] = temp;
//			X_I[i] = Temp_I[i];
//	}

}

/*=======================BEGIN: FFT=========================*/
//stage 1
void fft_stage_first(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {

//Insert your code here
	INTTYPE i;

	for (i = 0; i < SIZE; i = i + 2) {
// #pragma HLS UNROLL factor=8
// #pragma HLS PIPELINE
#pragma HLS LOOP_TRIPCOUNT min=512 max=512
		OUT_R[i]     = X_R[i] + X_R[i + 1];
		OUT_I[i]     = X_I[i] + X_I[i + 1];
		OUT_R[i + 1] = X_R[i] - X_R[i + 1];
		OUT_I[i + 1] = X_I[i] - X_I[i + 1];
	}
}

//stages
void fft_stages(DTYPE X_R[SIZE], DTYPE X_I[SIZE], int stage, DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {

//Insert your code here
	//Write a code that computes any arbitrary stages of the FFT
	INTTYPE i, j, k, x, y, z, a;
	DTYPE 	real_real, real_imag;
	DTYPE	imag_real, imag_imag;
	DTYPE	temp_R, temp_I;

	x = 1 << (stage - 1);
	y = 1 << stage;

	for (i = 0; i < SIZE; i = i + y) {
// #pragma HLS LOOP_TRIPCOUNT min=512 max=512
		for (j = 0; j < x; j++) {
// #pragma HLS LOOP_TRIPCOUNT min=512 max=512
#pragma HLS PIPELINE
			z = (j << 10) >> stage;
			k = (i + j) % SIZE;
			a = k + x;
			
			real_real = W_real[z] * X_R[a];
			real_imag = W_real[z] * X_I[a];
			
			imag_real = W_imag[z] * X_R[a];
			imag_imag = W_imag[z] * X_I[a];
			
			temp_R = real_real - imag_imag;
			temp_I = imag_real + real_imag;

			OUT_R[k] = X_R[k] + temp_R;
			OUT_I[k] = X_I[k] + temp_I;
			OUT_R[a] = X_R[k] - temp_R;
			OUT_I[a] = X_I[k] - temp_I;
		}

	}
}


//last stage
void fft_stage_last(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {

//Insert your code here
	INTTYPE i, z;
	INTTYPE a = SIZE >> 1;
	// DTYPE real_real, real_imag, imag_real, imag_imag, inner1, inner2;
	DTYPE real_real, real_imag, imag_real, imag_imag;
	DTYPE temp_R, temp_I;

	for (i = 0; i < a; i++) {
#pragma HLS PIPELINE
// #pragma HLS UNROLL factor=8
#pragma HLS LOOP_TRIPCOUNT min=512 max=512
		z = i + a;
		real_real = W_real[i] * X_R[z];
		real_imag = W_real[i] * X_I[z];
		imag_real = W_imag[i] * X_R[z];
		imag_imag = W_imag[i] * X_I[z];
		temp_R = real_real - imag_imag;
		temp_I = imag_real + real_imag;
		OUT_R[i] = X_R[i] + temp_R;
		OUT_I[i] = X_I[i] + temp_I;
		OUT_R[z] = X_R[i] - temp_R;
		OUT_I[z] = X_I[i] - temp_I;
	}
}
/*=======================END: FFT=========================*/




