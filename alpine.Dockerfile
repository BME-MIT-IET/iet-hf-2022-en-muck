FROM alpine:3.14.6

WORKDIR /entrypoint

RUN apk add gcc g++ make libc-dev 

COPY . .

RUN make purge

RUN make