# Ex 3.1
`31/ModuleSingle.h`

Initially we see the counter go up normally, one by one. Up until `7`, where instead of seeing a `8`, we get a `-8`

The counter is a 4 bit __signed__ integer. This means that the most significant bit (MSB) will  be used as a sign bit.
The counter starts at `0`, and up until `7` everything goes fine because we don't use the MSB (`0111` = `7` BIN to DEC).
However, when incrementing it once more we get `1000`, flipping the sign bit, turning our counter negative. 
Since most computers represent signed numbers with the Two's Compliment, the binary `1000` instead of being either an `8` or `-0` (we would see this if One's complement was used), gives us `-8`. Afterwards, adding to the counter is as expected, until we reach `7` again and we see the behaviour happen.

# Ex 3.2
`32/ModuleDouble.h`

# Ex 3.3
`33/ModuleTCP.h`
`33/TopTCP.h`

# Ex 3.4
`34/ModuleTCP.h`