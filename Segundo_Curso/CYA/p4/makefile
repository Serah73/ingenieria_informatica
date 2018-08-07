CXX=g++
CXXFLAGS=-g

OBJS = main.o transition.o state.o dfa.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o dfa ${OBJS}

clear:
	rm -rf *.o dfa
