#define NUM_SECTIONS 5 //3
typedef float data_t;
/*const data_t coeff_array[NUM_SECTIONS][6] = {
    { +0.9921264648, -1.9801635742, +0.9880371094, +1.0000000000, -1.9765014648, +0.9766845703 },
    { +0.9921264648, -1.9883422852, +0.9962158203, +1.0000000000, -1.9825439453, +0.9826660156 },
    { +0.9921264648, -1.9842529297, +0.9921264648, +1.0000000000, -1.9935302734, +0.9937133789 }
};*/
class IIRFilter {
public:
	data_t x[NUM_SECTIONS][3];
	data_t y[NUM_SECTIONS][3];
	data_t coeff_array[NUM_SECTIONS][6];
	IIRFilter() {
		for (int i = 0; i < NUM_SECTIONS; i++) {
			for (int j = 0; j < NUM_SECTIONS; j++) {
				x[i][j] = 0.0;
				y[i][j] = 0.0;
			}
		}
		for(int i=0; i< NUM_SECTIONS; i++)
			for (int j=0; j < 6; j++)
				coeff_array[i][j] =0;
	}
	void setCoeffs(data_t coefs[NUM_SECTIONS][6]) {
		for(int i=0; i< NUM_SECTIONS; i++) {
			setCoeffs_loop:for (int j=0; j < 6; j++) {
				coeff_array[i][j] = coefs[i][j];
			}
		}
	}
	data_t filter(data_t input) {
		data_t b0, b1, b2, a1, a2, a0, temp = input, acc;
		// loop over the Second Order Sections
		filter_loop:for(int i=0; i< NUM_SECTIONS; i++){
			// get coeffs
			b0=coeff_array[i][0];
			b1=coeff_array[i][1];
			b2=coeff_array[i][2];
			a0=coeff_array[i][3];
			a1=coeff_array[i][4];
			a2=coeff_array[i][5];
			// feed forward shift register
			x[i][2] = x[i][1];
			x[i][1] = x[i][0];
			x[i][0] = temp;
			// the filter
			acc = b0*x[i][0] / a0 + b1*x[i][1] / a0 + b2*x[i][2] / a0 - a1*y[i][1] / a0 - a2*y[i][2] / a0;
			y[i][0] = acc;

			// feedback shift register
			y[i][2] = y[i][1];
			y[i][1] = y[i][0];
			temp = y[i][0];
		}
		return temp;
	}

};

void equalizer(data_t *y, data_t x, int mode, data_t coeffs[NUM_SECTIONS][6]);
