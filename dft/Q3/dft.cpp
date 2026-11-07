#include<math.h> //Required for cos and sin functions
#include "dft.h"
// #include"coefficients32.h"
#include"coefficients32_2D.h"

// void dft(IN TYPE sample real[N], IN TYPE sample imag[N]) {
// Q1 and Q2
// void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE])
void dft(
    // Q3
    // Separated input and output arrays
    DTYPE real_input[SIZE], 
    DTYPE imag_input[SIZE],
    DTYPE real_output[SIZE], 
    DTYPE imag_output[SIZE]
)

{
//Write your code here
	
// int i, j;
int i;
int j;

// Data type for the temporary variables
// TEMP TYPE w;
// TEMP TYPE c, s;
// DTYPE w;
// DTYPE c;
// DTYPE s;

// Temporary arrays to hold the intermediate frequency domain results
// DTYPE temp_real[SIZE];
// DTYPE temp_imag[SIZE];

// Calculate each frequency domain sample iteratively
// for (i = 0; i < N; i += 1) {
for(i = 0; i < SIZE; i++)
{
    // temp real[i] = 0;
    DTYPE temp_real = 0.0f;
    // temp imag[i] = 0;
    DTYPE temp_imag = 0.0f;

    // // (2 ∗ pi ∗ i)/N
    // w = (2.0 ∗ 3.141592653589 / N) ∗ (TEMP TYPE)i;
    // w = (2.0*3.141592653589/SIZE)*(DTYPE)i;

    // Calculate the jth frequency sample sequentially
    // for (j = 0; j < N; j += 1) {
    for(j = 0; j < SIZE; j++)
    {
        // ----------- NOT USED BC USE LUT INSTEAD --------------
        // Q1 
        // Utilize HLS tool to calculate sine and cosine values
        // c = cos(j ∗ w);
        // c = cos(j*w);
        // s = −sin(j ∗ w);
        // s = -sin(j*w);
        
        // Multiply the current phasor with the appropriate input sample and keep
        // running sum
        // temp real[i] += (sample real[j] ∗ c − sample imag[j] ∗ s);
        // temp_real[i] += (real_sample[j]*c - imag_sample[j]*s);
        // temp imag[i] += (sample real[j] ∗ s + sample imag[j] ∗ c);
        // temp_imag[i] += (real_sample[j]*s + imag_sample[j]*c);
        // ------------------------------------------------------
        
        // Q2
        // temp_real[i] += (real_sample[j] * cos_coeff_table[i][j] - imag_sample[j]  * sin_coeff_table[i][j]);
        // temp_imag[i] += (real_sample[j] * sin_coeff_table[i][j]  + imag_sample[j]  * cos_coeff_table[i][j]);

        temp_real += (real_input[j] * cos_coeff_table[i][j] - imag_input[j]  * sin_coeff_table[i][j]);
        temp_imag += (real_input[j] * sin_coeff_table[i][j]  + imag_input[j]  * cos_coeff_table[i][j]);
    }

// Q1 and Q2
// Perform an inplace DFT, i.e., copy result into the input arrays
// for (i = 0; i < N; i += 1) {
// for( i = 0; i < SIZE; i++)
//    {
//        // sample real[i] = temp real[i];
//        real_sample[i] = temp_real[i];
//        // sample imag[i] = temp imag[i];
//        imag_sample[i] = temp_imag[i];
    real_output[i] = temp_real;
    imag_output[i] = temp_imag;

    }
}


