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
	data_t aasdasdas[NUM_SECTIONS][6];
	std::complex<data_t> x, y_img;
	data_t y, temp;
	double freq, phase, rate;
	double zoom = 32;
	rate = 2.0*M_PI/(zoom*Nsim); freq = -M_PI/zoom; phase = 0.0;

	std::cout << "writing lfm.dat\n";
	std::ofstream outf2("./lfm.dat");
	for (int i=0; i<Nsim; i++){
		phase += freq;
	    freq  += rate;
	    x = exp(j*phase);
	    temp = x.real();
	    equalizer(&y, temp, 1,aasdasdas);
	    //y.real(equalizer(x.real()));
	    //y.imag(equalizer(x.imag()));
	    //double absval = sqrt( double(y.real())*double(y.real()) + double(y.imag())*double(y.imag()));
	    outf2 << x.real() << "  " << x.imag() << "  " << y << "  ";
	    temp = x.imag();
	    equalizer(&y, temp,1, aasdasdas);
	    outf2 << y << "\n";

	}

	return(0);
}
