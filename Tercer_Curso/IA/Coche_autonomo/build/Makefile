CC=			g++
CFLAGS=		-I$(IDIR) -std=c++11 -g

IDIR=		../headers
ODIR=		../src
FDIR=		../outs
LDIR=		../lib

LIBS=		-lm

_OBJS =	main.o	car.o	ant.o	grid.o	machine.o
OBJS = $(patsubst %,$(FDIR)/%,$(_OBJS))

all: test

$(FDIR)/ant.o: $(ODIR)/ant.cpp $(IDIR)/ant.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(FDIR)/car.o: $(ODIR)/car.cpp $(IDIR)/car.hpp $(IDIR)/grid.h $(IDIR)/ant.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(FDIR)/grid.o: $(ODIR)/grid.cpp $(IDIR)/grid.h $(IDIR)/car.hpp $(IDIR)/grid.h 
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(FDIR)/machine.o: $(ODIR)/machine.cpp $(IDIR)/machine.h $(IDIR)/car.hpp $(IDIR)/grid.h $(IDIR)/termcolor.hpp $(IDIR)/grid.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(FDIR)/main.o: $(ODIR)/main.cpp $(IDIR)/machine.h $(IDIR)/car.hpp $(IDIR)/grid.h $(IDIR)/ant.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
test: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(FDIR)/*.o *~ $(INCDIR)/*~