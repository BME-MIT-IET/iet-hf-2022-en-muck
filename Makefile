#--------------------------------------
# Makefile for all Recommender packages
#--------------------------------------

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

test:
	- ( cd test_suite && $(MAKE) all)
	- ( ./test_suite/test_all )

coverage:
	- ( echo "Coverage is not supported on Alpine Linux" )

alpine:
	- (docker build -t recommender:alpine3.14.6 -f alpine.Dockerfile .)

debian:
	- (docker build -t recommender:debian9.13 -f debian.Dockerfile .)
