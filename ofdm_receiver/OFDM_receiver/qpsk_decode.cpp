#include "fft.h"
#include <stdio.h>

void qpsk_decode(DTYPE R[SIZE], DTYPE I[SIZE], int D[SIZE]) {

	//Write your code here

	// QPSK Decoder Constellation Plot
	for (int i = 0; i < SIZE; ++i)
	{
		// quadrant I R+, I+
		if (R[i]>0 && I[i]>0)
			D[i] = 0;

		// quadrant II R-, I+
		else if (R[i]<0 && I[i]>0)
			D[i] = 1;

		// quadrant III R+, I-
		else if(R[i]>0 && I[i]<0)
			D[i] = 2;

		// quadrant IV R-, I-
		else if(R[i]<0 && I[i]<0)
			D[i] = 3;
	}
}