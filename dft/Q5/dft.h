
typedef float DTYPE; // Data type for the input signal // Data type for the temporary variables
#define SIZE 32 		/* SIZE OF DFT */ 
// Q1 and Q2
// void dft(DTYPE XX_R[SIZE], DTYPE XX_I[SIZE]);
 void dft(
    // Q3
    // Separated input and output arrays
    DTYPE real_input[SIZE], 
    DTYPE imag_input[SIZE],
    DTYPE real_output[SIZE], 
    DTYPE imag_output[SIZE]
);
