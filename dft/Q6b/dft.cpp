#include<math.h>
#include "dft.h"
#include"coefficients1024.h"

void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE],DTYPE real_op[SIZE],DTYPE imag_op[SIZE])	//Use pointers while doing the demo for streaming//
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

double w;
double c;
double s;

const double PI = 3.141592653589;

// Calculate each frequency domain sample iteratively
// for (i = 0; i < N; i += 1) {
for(i = 0; i < SIZE; i++)
{
    // temp real[i] = 0;
    // DTYPE temp_real = 0.0f;
    double temp_real = 0.0;

    // temp imag[i] = 0;
    // DTYPE temp_imag = 0.0f;
    double temp_imag = 0.0;

    // // (2 ∗ pi ∗ i)/N
    // w = (2.0 ∗ 3.141592653589 / N) ∗ (TEMP TYPE)i;
    // w = (2.0*3.141592653589/SIZE)*(DTYPE)i;
    // w = (2.0*PI/(double)SIZE)*(double)i;

    // Calculate the jth frequency sample sequentially
    // for (j = 0; j < N; j += 1) {
    for(j = 0; j < SIZE; j++)
    {
        // Utilize HLS tool to calculate sine and cosine values
        // c = cos(j ∗ w);
        // c = cos(j*w);
        // double c = cos((double)j*w);
        
        // s = −sin(j ∗ w);
        // s = -sin(j*w);
        // double s = -sin((double)j*w);

        int lut_index = (i*j) % SIZE;
        double c = (double)cos_coefficients_table[lut_index];
        double s = (double)sin_coefficients_table[lut_index];

        // Multiply the current phasor with the appropriate input sample and keep
        // running sum
        // temp real[i] += (sample real[j] ∗ c − sample imag[j] ∗ s);
        // temp_real += (real_sample[j]*c - imag_sample[j]*s);
        // temp_real += ((double)real_sample[j]*c - (double)imag_sample[j]*s);
        temp_real += ((double)real_sample[j] * c - (double)imag_sample[j]  * s);


        // temp imag[i] += (sample real[j] ∗ s + sample imag[j] ∗ c);
        // temp_imag += (real_sample[j]*s + imag_sample[j]*c);
        // temp_imag += ((double)real_sample[j]*s + (double)imag_sample[j]*c);
        temp_imag += ((double)real_sample[j] * s  + (double)imag_sample[j]  * c);


    }

// Q1 and Q2
// Perform an inplace DFT, i.e., copy result into the input arrays
// for (i = 0; i < N; i += 1) {
 //for( i = 0; i < SIZE; i++)
    // {
        // sample real[i] = temp real[i];
        // real_op[i] = temp_real;
        real_op[i] = (DTYPE)temp_real;

        // sample imag[i] = temp imag[i];
        // imag_op[i] = temp_imag;
        imag_op[i] = (DTYPE)temp_imag;

    }
}


