#include "SpiWrapper.h"

#include <iostream>
#include <stdlib.h>

SpiWrapper::SpiWrapper()
{
    spi_config_t spiConfig;

    spiConfig.mode=0;
    spiConfig.speed=1000000;
    spiConfig.delay=0;
    spiConfig.bits_per_word=8;

    // The device spidev0.0 is SPI bus 0, with Chip Select pin 0.
    // (But we're not using the Chip Select pin for now.)
    const char spiDeviceFilename[] = "/dev/spidev0.0";

    std::cout << "Trying to open SPI device with path " << spiDeviceFilename << ".\n";

    spiDevice = std::make_unique<SPI>(spiDeviceFilename, &spiConfig);

    const bool successfulInit = spiDevice->begin();

    if (successfulInit)
    {
        std::cout << "Successfully opened the SPI device!\n";
    }
    else
    {
        std::cout << "Failed to open the SPI device - aborting the program!\n";
        std::exit(EXIT_FAILURE);
    }
}

SpiWrapper::SpiMessage SpiWrapper::sendAndReceive(SpiWrapper::SpiMessage messageToTransmit)
{
    /*
    It looks like the xfer function ignores the p_rxlen parameter and happily
    writes p_txlen bytes to the rxBuffer, but we provide the same length to
    both parameters, just to be safe.
    */
    const std::size_t bufferLength = messageToTransmit.size();
    SpiMessage receivedMessage(bufferLength, 0);
    spiDevice->xfer(messageToTransmit.data(), bufferLength, receivedMessage.data(), bufferLength);

    return receivedMessage;
}