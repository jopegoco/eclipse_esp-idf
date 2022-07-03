#I2C Scanner An I2C Scanner sends a start/stop request to each of the possible addresses on the bus. Those that are present return with an ACK. This can be used to detect the presence/absence of a device at that address. The results are logged to the serial output.

While studying I2C, I wanted to see what it would take to create an equivalent of the "i2cdetect" tool found on Linux. This is a useful tool that pings each I2C address to see if anyone responds. Fortunately, this wasn't too difficult and I offer the following as an example:

https://github.com/nkolban/esp32-snippe ... cscanner.c

An illustrative output might be:

Code: Select all

     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: 20 -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- -- --
