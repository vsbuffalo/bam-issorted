CC=clang++
CFLAGS=-g -O0 --std=c++11

BAMTOOLS_ROOT=bamtools
INCLUDE = -I$(BAMTOOLS_ROOT)/src
LIBS=-L$(BAMTOOLS_ROOT)/lib -lz -lm

all: issorted

# builds bamtools static lib, and copies into root
$(BAMTOOLS_ROOT)/lib/libbamtools.a:
	cd $(BAMTOOLS_ROOT) && mkdir -p build && cd build && cmake .. && $(MAKE)

issorted: issorted.cpp $(BAMTOOLS_ROOT)/lib/libbamtools.a
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)
