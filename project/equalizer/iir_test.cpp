#include "iir.h"
#include <fstream>
#include <iostream>
#include <complex>
#include <cmath>

int main() {
	IIRFilter iir_real, iir_imag;

	// test frequency response with linear fm signal.
	const int Nsim = 64;
	const std::complex<double> j(0.0, 1.0);
	std::complex<data_t> x, y_img;
	data_t y, temp;
	double freq, phase, rate;
	double zoom = 32;
	rate = 2.0*M_PI/(zoom*Nsim); freq = -M_PI/zoom; phase = 0.0;
	float coeffs[5][6] = {
			{1.00135159, -1.99992692, 0.998648345, 1.00013518, -1.99992692, 0.999864817},
			{1.00518036, -1.99892628, 0.994819641, 1.00051808, -1.99892628, 0.999481976},
			{1.02044261, -1.98321366, 0.979557455, 1.0020442, -1.98321366, 0.997955739},
			{1.08531046, -1.68390632, 0.914689541, 1.00853109, -1.68390632, 0.991468966},
			{1.14412177, 0.822573423, 0.855878234, 1.01441216, 0.822573423, 0.985587835},
	};
	equalizer(&y, temp, 0,coeffs);
	std::cout << "writing lfm.dat\n";
	std::ofstream outf2("./lfm.dat");
	for (int i=0; i<Nsim; i++){
		phase += freq;
	    freq  += rate;
	    x = exp(j*phase);
	    temp = x.real();
	    equalizer(&y, temp, 1,coeffs);
	    //y.real(equalizer(x.real()));
	    //y.imag(equalizer(x.imag()));
	    //double absval = sqrt( double(y.real())*double(y.real()) + double(y.imag())*double(y.imag()));
	    outf2 << x.real() << "  " << x.imag() << "  " << y << "  ";
	    temp = x.imag();
	    equalizer(&y, temp,1, coeffs);
	    outf2 << y << "\n";

	}

	return(0);
}
