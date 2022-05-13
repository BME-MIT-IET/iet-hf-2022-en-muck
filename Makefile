#--------------------------------------
# Makefile for all Recommender packages
#--------------------------------------

MAKEFILE := $(firstword $(MAKEFILE_LIST))

default:
	- ( cd src && $(MAKE) all )
	- ( cd tools/kfold && $(MAKE) all )
	- ( cd tools/serialization && $(MAKE) all )
all:
	- ( cd src && $(MAKE) all )
	- ( cd tools/kfold && $(MAKE) all )
	- ( cd tools/serialization && $(MAKE) all )

purge:
	- ( cd src && $(MAKE) purge )

clean:
	- ( cd src && $(MAKE) clean )
	- ( cd tools/kfold && $(MAKE) clean )
	- ( cd tools/serialization && $(MAKE) clean )

.PHONY: all test clean
test:
	gcc -fprofile-arcs -ftest-coverage test_suite/test_*.c src/libRecommender.a -lm -o test_suite/test_all.o
	./test_suite/test_all.o

coverage:
	gcov test_all.c
	lcov --capture --directory . --output-file coverage.info

alpine:
	docker build -t recommender:alpine3.14.6 -f alpine.Dockerfile .

debian:
	docker build -t recommender:debian9.13 -f debian.Dockerfile .