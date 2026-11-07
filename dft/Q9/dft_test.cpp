/*
This is DFT computation using matrix vector multiplication form.
INPUT:
	In_R, In_I[]: Real and Imag parts of Complex signal in time domain.
OUTPUT:
	Out_R, Out_I[]: Real and Imag parts of Complex signal in frequency domain.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
#include "dft.h"

struct Rmse
{
    int num_sq;
    float sum_sq;
    float error;

    Rmse(){num_sq = 0; sum_sq = 0.0; error = 0.0; }

    float add_value(float d_n)
    {
        num_sq++;
        sum_sq += d_n * d_n;
        error = sqrtf(sum_sq / num_sq);
        return error;
    }
    
};

static axis_float_t make_axis_word(
    // DTYPE real_value,
    // DTYPE imag_value,
    DTYPE value,
    bool is_last
)
{
    union {
        unsigned int uint_value;
        float float_value;
    } converter;
    // real_converter, imag_converter;

    // real_converter.float_value = real_value;
    // imag_converter.float_value = imag_value;
    converter.float_value = value;

    // axis_complex_t word;
    axis_float_t word;

    // word.data.range(31, 0) = real_converter.uint_value;
    // word.data.range(63, 32) = imag_converter.uint_value;
    word.data = converter.uint_value;

    word.keep = -1;
    word.strb = -1;
    word.last = is_last;

    return word;
}

// static DTYPE get_real(axis_complex_t word)
static DTYPE axis_word_to_float(axis_float_t word)
{
    union {
        unsigned int uint_value;
        float float_value;
    } converter;

    // converter.uint_value = (unsigned int)word.data.range(31, 0);
    converter.uint_value = (unsigned int)word.data;

    return converter.float_value;
}

// DTYPE In_R[SIZE], In_I[SIZE],Out_R[SIZE],Out_I[SIZE];   //Modify the testbench while checking for demo. You will have to access the data variable of the structure//
int main()
{
    Rmse rmse_R;
    Rmse rmse_I;

    hls::stream<axis_float_t> real_input_stream("real_input_stream");
    hls::stream<axis_float_t> imag_input_stream("imag_input_stream");
    hls::stream<axis_float_t> real_output_stream("real_output_stream");
    hls::stream<axis_float_t> imag_output_stream("imag_output_stream");

    FILE *fp = fopen("out.gold.dat", "r");

    if (fp == NULL) {
        printf("ERROR: Could not open out.gold.dat\n");
        return 1;
    }

// WRITE_INPUT_STREAMS:
// getting input data
    for (int i = 0; i < SIZE; i++) {
        // In_R[i] = i;
        DTYPE real_input_value = (DTYPE)i;
        // In_I[i] = 0.0;
        DTYPE imag_input_value = 0.0f;

        bool is_last = (i == SIZE - 1);

       // input_stream.write(
       //     make_axis_word(
       //         real_value,
       //         imag_value,
       //         i == SIZE - 1
       //            )
       //);

        real_input_stream.write(make_axis_word(real_input_value, is_last));
        imag_input_stream.write(make_axis_word(imag_input_value, is_last));
    }

    // DFT
	// dft(In_R, In_I,Out_R,Out_I);
    dft(real_input_stream, imag_input_stream, real_output_stream, imag_output_stream);

// READ_AND_COMPARE_OUTPUT_STREAMS:
	// comparing with golden output
    for (int i = 0; i < SIZE; i++) {
        int index;
        float gold_R;
        float gold_I;

        fscanf(fp, "%d %f %f", &index, &gold_R, &gold_I);

        // axis_complex_t output_word = output_stream.read();
        axis_float_t output_real = real_output_stream.read();
        axis_float_t output_imag = imag_output_stream.read();

        DTYPE actual_real = axis_word_to_float(output_real);
        DTYPE actual_imag = axis_word_to_float(output_imag);

        // rmse_R.add_value(output_real - gold_R);
        rmse_R.add_value(actual_real - gold_R);
        // rmse_I.add_value(output_imag - gold_I);
        rmse_I.add_value(actual_imag - gold_I);

        bool expected_last = (i == SIZE - 1);

        if ((bool)output_real.last != expected_last) {
            printf("FAIL: Incorrect real-output TLAST at index %d\n", i);
            fclose(fp);
            return 1;
        }

        if ((bool)output_imag.last != expected_last) {
            printf("FAIL: Incorrect imag-output TLAST at index %d\n", i);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

	// printing error results
	printf("----------------------------------------------\n");
	printf("   RMSE(R)           RMSE(I)\n");
	printf("%0.15f %0.15f\n", rmse_R.error, rmse_I.error);
	printf("----------------------------------------------\n");

	if (rmse_R.error > 0.1 || rmse_I.error > 0.1 ) {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
		fprintf(stdout, "*******************************************\n");
	    return 1;
	}else {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "PASS: The output matches the golden output!\n");
		fprintf(stdout, "*******************************************\n");
	    return 0;
	}
}