#include "fft.h"
#define MAX_SAMPLES 35000

static unsigned short count;
static DTYPE xr[ SIZE ];
static DTYPE xi[ SIZE ];
static DTYPE xr_out[ SIZE ];
static DTYPE xi_out[ SIZE ];
static int   dout[ SIZE ];

// void ofdm_receiver( volatile DTYPE *inptr, volatile uint32_t *outptr )
static void ofdm_receiver_core( volatile DTYPE in_real, volatile DTYPE in_imag, volatile uint32_t *outptr )
{
// #pragma AP interface ap_fifo port=inptr
// #pragma AP interface ap_fifo port=outptr
// #pragma AP interface ap_ctrl_none port=return
#pragma HLS INLINE off

	*outptr++ = dout[ count ];

	xr[ count ] = in_real;
	xi[ count ] = in_imag;
	count++;
	if( count == 1024 ){
		count = 0;
		demod( xr, xi, dout, xr_out, xi_out );
	}
}

void ofdm_receiver_axi(const DTYPE *in_data, uint32_t *out_data, int num_samples)
{
#pragma HLS INTERFACE m_axi port=in_data \
    offset=slave \
    bundle=gmem_in \
    depth=70000 \
    max_read_burst_length=64

#pragma HLS INTERFACE m_axi port=out_data \
    offset=slave \
    bundle=gmem_out \
    depth=35000 \
    max_write_burst_length=64

#pragma HLS INTERFACE s_axilite port=in_data bundle=control
#pragma HLS INTERFACE s_axilite port=out_data bundle=control
#pragma HLS INTERFACE s_axilite port=num_samples bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    if (num_samples < 0) {
        num_samples = 0;
    }

    if (num_samples > MAX_SAMPLES) {
        num_samples = MAX_SAMPLES;
    }

    for (int i = 0; i < num_samples; i++) {
        DTYPE input_real = in_data[2 * i];
        DTYPE input_imag = in_data[(2 * i) + 1];
        uint32_t decoded_symbol;
        ofdm_receiver_core(input_real, input_imag, &decoded_symbol);
        out_data[i] = decoded_symbol;
    }
}