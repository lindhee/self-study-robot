/*
An example program to show how to use the SPI wrapper.
*/

#include "SpiWrapper.h"

#include <iostream>

int main()
{
    auto spi = SpiWrapper();

    auto returnMessage = spi.sendAndReceive({11, 22, 33, 44, 55});

    std::cout << "** Start of response **\n";
    for (auto &x : returnMessage)
    {
        std::cout << static_cast<int>(x) << std::endl;
    } 
    std::cout << "** End of message **\n";

    return 1;
}