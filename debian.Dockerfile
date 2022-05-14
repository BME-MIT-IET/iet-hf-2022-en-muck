FROM arm64v8/debian:9.13

RUN apt update && apt upgrade -y

WORKDIR /entrypoint

RUN apt install -y gcc g++ make libc6-dev 

COPY . .

RUN make purge

RUN make

RUN gcc -fprofile-arcs -ftest-coverage test_suite/test_*.c src/libRecommender.a -lm -o test_suite/test_all.o

RUN ./test_suite/test_all.o  >> test.log