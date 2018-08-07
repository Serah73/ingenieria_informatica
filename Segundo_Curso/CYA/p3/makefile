CXX=g++
CXXFLAGS=-g

OBJS = state.o dfa.o main.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o dfa ${OBJS}

clear:
	rm -rf *.o dfa
