#include "cordiccart2pol.h"

data_t Kvalues[NO_ITER] = {1,	0.500000000000000,	0.250000000000000,	0.125000000000000,	0.0625000000000000,	0.0312500000000000,	0.0156250000000000,	0.00781250000000000,	0.00390625000000000,	0.00195312500000000,	0.000976562500000000,	0.000488281250000000,	0.000244140625000000,	0.000122070312500000,	6.10351562500000e-05,	3.05175781250000e-05};

data_t angles[NO_ITER] = {0.785398163397448,	0.463647609000806,	0.244978663126864,	0.124354994546761,	0.0624188099959574,	0.0312398334302683,	0.0156237286204768,	0.00781234106010111,	0.00390623013196697,	0.00195312251647882,	0.000976562189559320,	0.000488281211194898,	0.000244140620149362,	0.000122070311893670,	6.10351561742088e-05,	3.05175781155261e-05};

const data_t pi_div_2 = 1.5707963267948966;

void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta)
{
	#pragma HLS INTERFACE mode=s_axilite port=return
	#pragma HLS INTERFACE mode=s_axilite port=x
	#pragma HLS INTERFACE mode=s_axilite port=y
	#pragma HLS INTERFACE mode=s_axilite port=r
	#pragma HLS INTERFACE mode=s_axilite port=theta
	// Write your code here
    data_t tempX;
	*theta = 0;

    // Quadrant I or II
	if (x < 0) {
		tempX = x;

        // +/- 90 degree rotation
		if (y > 0) {
			x = y;
			y = -tempX;
			*theta += pi_div_2;

		} else {
			x = -y;
			y = tempX;
			*theta -= pi_div_2;
		}
	}

    // Quadrant III or IV
	for(iter_t i_idx = 0; i_idx < NO_ITER; i_idx++) {

		tempX = x;
		if (y > 0) {

			// x += y * Kvalues[i_idx];
			x += (y>>i_idx);
			
			// y -= tempX * Kvalues[i_idx];
			y -= (tempX>>i_idx);

			*theta += angles[i_idx];
            
		} else {
			// x -= y * Kvalues[i_idx];
			x -= (y>>i_idx);

			// y += tempX * Kvalues[i_idx];
			y += (tempX>>i_idx);

			*theta -= angles[i_idx];
		}
	}


    // K_values(16) = prod(1 ./ sqrt(1 + 2.^(-2 * 16))); = 0.6072529350088812561694f
	// *r  = x * 0.6072529350088812561694f;
	*r  = (x>>1) + (x>>2) - (x>>3) - (x>>4) + (x>>5) + (x>>6) - (x>>7) + (x>>8) + (x>>9) - (x>>10) + (x>>11);

}

