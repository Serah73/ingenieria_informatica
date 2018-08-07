CC=g++
CFLAGS=-c -std=c++11
LDFLAGS=
SOURCES=main.cpp DNI.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=executable

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm -f *.o $(OBJECTS)