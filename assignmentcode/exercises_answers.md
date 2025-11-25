# Ex 3.1
`31/ModuleSingle.h`

Initially we see the counter go up normally, one by one. Up until `7`, where instead of seeing a `8`, we get a `-8`

The counter is a 4 bit __signed__ integer. This means that the most significant bit (MSB) will  be used as a sign bit.
The counter starts at `0`, and up until `7` everything goes fine because we don't use the MSB (`0111` = `7` BIN to DEC).
However, when incrementing it once more we get `1000`, flipping the sign bit, turning our counter negative. 
Since most computers represent signed numbers with the Two's Compliment, the binary `1000` instead of being either an `8` or `-0` (we would see this if One's complement was used), gives us `-8`. Afterwards, adding to the counter is as expected, until we reach `7` again and we see the behaviour happen.

**!attach images of gtkwave or console**

# Ex 3.2
`32/ModuleDouble.h`

By setting the static sensitivity in the constructor, using the syntax `sensitive << eventX << eventY`,  we can set which events will trigger the last process defined without having to write it in the process function code.
Dynamic sensitivity works the same but it's called on the process function using either of the following functions: `wait(<time or event>)` or `next_trigger(<event>)`.
The exercise essentially requires to use both sensitivities. 

On `methodA`, we first use static sensitivity so that it is sensitive to either of the events sent by proccess `A` or `B`, whichever comes first. After that, by using `next_trigger()` as required, we are using dynamic sensitivity to define which event will trigger the method next.
On the processes `A` and `B`, we just use dynamic sensitivity that mostly acts as static since each thread waits for it's corresponding `Ack` event.

**!attach images of gtkwave or console**

# Ex 3.3
`33/ModuleTCP.h`
`33/TopTCP.h`

This exercise required the creation of 3 modules, a `Producer`, a `Receiver` and the `Top` module.

The `Producer` and `Receiver` are both connected with a `FIFO`, using, internally, the classes `sc_fifo_out` and `sc_fifo_in`, respectively, to transmit the data.
The `Producer` will instantiate a new TCP packet and send it using the `FIFO`, while the Receiver just calls the method `read()`. This method is blocking, so only after the `Producer` writes something to the `FIFO`, will the `Receiver` do something. Because of this, there's no static sensitivity to be defined in the constructor.
After this, in order to be able to have multiple `Receiver`s reading the `FIFO`, the `sc_fifo_out` class (using it's interface, suffixed with `_if`) has to be wrapped in the `sc_port` class, setting the number of connections to 0 to remove any limit in the amount of connections possible to the port. This `sc_port` class acts like a pointer to the `FIFO` channel for each `Receiver`, and allows for better control of how many modules can connect to this channel. 

**!attach images of gtkwave or console**

# Ex 3.4
`34/conf.h` `34/AvalonSTTop.h` `34/ModuleSlave.h` `34/ModuleMaster.h`

The values defined in the header file in the exercise are to be used as the value inside the `sc_int` class, when creating the various signals, channels and ports.

In order to have cicle accurate we must make use of the `wait()`, with no parameters, so that it waits for the next clock. This is set by making the process sensitive to the clock signal, in the constructor (static sensitivity).
To replicate the 5.8 image mentioned, the `ModuleSlave` must send a ready signal, for which, the `ModuleMaster` is constantly reading and waiting for it to turn to 1. After that, to make it such that the `valid` and `data` signals send their corresponding values in the next clock positive, we must call the `wait()` function to create the delay.
After the `valid` signal turning to 1, the `ModuleSlave` can now read the value and turn the `ready` signal to 0 to complete the transaction.

**!attach images of gtkwave or console. use the .vcd and .slv files. Use the files in commit with revision cbed67c3e40f9a3e15c4aee6fa4a2a0a6cd83bff**

# Ex 3.5
`35/conf_35.h` `35/Top35.h` `35/ModuleSlave_35.h` `35/ModuleMaster_35.h` `35/InAdapter.h`

In order for the model to represent both TLM and BCAM levels of transmitting data, we can adapt the previous exercise's model such that the `Master` represents the TLM and the `Slave` the BCAM level, respectively. 

To do this, we must add a new module, `InAdapter`, in between the 2 other modules. The `Master` will now first communicate with `InAdapter`, via a `FIFO`, which gives us the TLM level, where only the communication is modelled.
The communication between the `InAdapater` and the `Slave` will behave in the same way as the exercise 3.4, which models the BCAM, since there are multiple channels being used to establish the transaction, as well as the usage of clock and reset signals.

**!attach images of gtkwave or console. use the .vcd and .slv files. Use the files in commit with revision cbed67c3e40f9a3e15c4aee6fa4a2a0a6cd83bff**
