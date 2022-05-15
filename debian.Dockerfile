FROM debian:9.13

RUN apt update && apt upgrade -y

WORKDIR /entrypoint

RUN apt install -y gcc g++ make libc6-dev 

COPY . .

RUN make purge

RUN make
