FROM debian:bullseye AS base

WORKDIR /workspace
#Update & upgrade
RUN apt-get update && apt-get upgrade -y
RUN apt-get install ca-certificates gpg wget -y
RUN apt-get install build-essential libtool autoconf unzip -y
RUN apt-get install libssl-dev -y

# this shoud go in another image or in a step
# version=4.0
# build=3
RUN mkdir temp
WORKDIR /workspace/temp
RUN wget https://cmake.org/files/v4.0/cmake-4.0.3.tar.gz
RUN tar -xzvf cmake-4.0.3.tar.gz
WORKDIR /workspace/temp/cmake-4.0.3/
RUN ./bootstrap
RUN make -j$(nproc)
RUN make install
WORKDIR /workspace
RUN rm -r temp

FROM base

COPY src /workspace/src
WORKDIR src
RUN cmake build .
RUN make

ENTRYPOINT ["./KKMBackend"]

