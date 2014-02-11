CC=clang++
CFLAGS=-g -O0 --std=c++11

BAMTOOLS_ROOT=bamtools
INCLUDE = -I$(BAMTOOLS_ROOT)/src
LIBS=-L$(BAMTOOLS_ROOT)/lib -lz -lm

issorted: issorted.cpp
			$(CC) $(CFLAGS) $(LIBS) $(INCLUDE) -o $@ $^
