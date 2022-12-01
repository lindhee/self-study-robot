FROM arm64v8/ros:humble

ENV WORKSPACE=/ws

# Get the SPI interface code and build it
RUN mkdir -p $WORKSPACE \
    && cd $WORKSPACE \
    && git clone https://github.com/milekium/spidev-lib.git \
    && cd spidev-lib \
    && mkdir build \
    && cd build \
    && cmake ../ \
    && make \
    && make install

# Copy our own C++ wrapper code
RUN cd $WORKSPACE \
    && mkdir -p wrapper
COPY ./wrapper $WORKSPACE/wrapper



