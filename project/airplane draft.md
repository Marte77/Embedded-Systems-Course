# why use hls instead of systemc
Equalizers are a very ubiquitous application, being present as stand-alone devices that only use electrical engineering to achieve the filtering or as a software only solution as one might find in an smartphone. 
this means that there are plenty of ways of achieving a user customizable equalizer and that we don't have to necessarily worry about processor timings, as long as the output audio is clean enough and with low latency.

so, in order to achieve a low latency, good quality equalizer using the Zybo Z7 FPGA, we can create a hardware component that is in charge of applying the coefficients that will give us the desired output. This allows the CPU to handle other operations when the audio is being processed, as that operation is being done outside of the ARM CPU.

The reason why we chose to go with HLS is because the huge amount of detail that SystemC gives us is not super necessary, since clock timings and the like aren't hugely important when the benchmark is human hearing.

# explaining the HLS code
The code itself is pretty simple, there are 2 files, iir.cpp and iir.h and a top function called `equalizer()`, that receives an input signal (x) and writes it to the output parameter(y).
```cpp
void equalizer(data_t *y, data_t x, int mode, data_t coeffs[NUM_SECTIONS][6]) {
	static IIRFilter iir;
	if (mode == 1)
		 *y = iir.filter(x);
	else {
		iir.setCoeffs(coeffs);
	}
}
```
It also contains 2 other parameters, mode and coeffs. These allow for the dynamic setting of the coefficients used for filtering. The coeffs parameter is a 2D array NUM_SECTIONS(5) by 6, where the NUM_SECTIONS value corresponds to the number of frequency bands being filtered (in our case, 60, 230, 910, 4000 and 14000 Hz).
Another thing worth mentioning is declaring the IIRFilter class as static so that it is kept in memory for the entire runtime of the board.

In the iir.h file, we have the IIRFilter class declared. Here we can see how HLS is incredibly helpful in allowing the creation of hardware using just C/C++ code. We have a class declared with 2 methods, one that sets the coefficients stored in memory, and another that applies these coefficients to the audio samples received. Doing this in plain VHDL/Verilog or SystemC would've been incredibly time consuming, but with HLS it's as simple as reusing code written for software applications.

```cpp
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
		data_t b0, b1, b2, a1, a2, temp = input, acc;
		// loop over the Second Order Sections
		filter_loop:for(int i=0; i< NUM_SECTIONS; i++){
			// get coeffs
			b0=coeff_array[i][0];
			b1=coeff_array[i][1];
			b2=coeff_array[i][2];
			a1=coeff_array[i][4];
			a2=coeff_array[i][5];
			// feed forward shift register
			x[i][2] = x[i][1];
			x[i][1] = x[i][0];
			x[i][0] = temp;
			// the filter
			acc = b0*x[i][0] + b1*x[i][1] + b2*x[i][2] - a1*y[i][1] - a2*y[i][2];
			y[i][0] = acc;

			// feedback shift register
			y[i][2] = y[i][1];
			y[i][1] = y[i][0];
			temp = y[i][0];
		}
		return temp;
	}
};

```

## Directives

Directives allow for specifying certain optimizations or specifications that could be made in the VHDL that the compiler wouldn't be able to catch by itself. We used three:
- INTERFACE: This directive was applied to all of the top function's parameters. It tells HLS to merge all the ports that would be otherwise generated into a single bundled port. In this case, it was an AXI_LITE port. This massively simplifies the design in the Vivado project since there's only one connection made for all 4 of the parameters, and it all uses AXI (i dont know if "Using AXI" is a correct term??)
- PIPELINE: TODO I DONT HAVE INTERNET SO I CANT REALLY EXPLAIN PIPLEINE WITHOUT DOCUMENTATION
- FLATTEN: This directive is applied to the setCoeffs(). It allows HLS to "spread" the loop so that it is not made sequentially, as you would expect just by reading the code. This massively improves performances in certain scenarios, however, here it's not a huge deal since the arrays aren't big and the operation is done in "human" time (probably rephrase this to something like "a person will not be setting the gain every 100ms")

## HLS Synthesising Results

Since there are no coefficients being calculated in this IP Core, the synthesis reports show very little usage of components (idk if components is the correct words, im talking about flip flops, BRAM_18K, etc usage). I