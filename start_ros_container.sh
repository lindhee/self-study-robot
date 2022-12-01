#!/bin/bash
docker run -it --privileged --volume /home/robot/code:/mnt/ --device /dev/spidev0.0:/dev/spidev0.0:rw  humble_spi

