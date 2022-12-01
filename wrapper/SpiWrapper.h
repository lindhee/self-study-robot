/*
A wrapper for the spidev-lib library from 
https://github.com/milekium/spidev-lib
adapted to the Ericsson Research (GFTL ER HDE CPS Decision & Control)
self-study robot project.

This wrapper is based on the C++ example code from the repo above,
but the purpose is to expose a simplified C++-compliant interface 
for our code to work against.
*/

#include <memory>
#include <spidev_lib++.h>
#include <vector>

class SpiWrapper
{
    public:
        typedef std::vector<unsigned char> SpiMessage; 

        /// Connect to SPI 0, chip select pin 0.
        SpiWrapper();

        /// With SPI, we always receive as many bytes as we transmit.
        SpiMessage sendAndReceive(SpiMessage messageToTransmit);
    
    private:
        std::unique_ptr<SPI> spiDevice;
};

