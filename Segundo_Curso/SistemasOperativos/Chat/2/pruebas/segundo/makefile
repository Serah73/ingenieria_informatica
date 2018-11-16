CC=g++
CFLAGS=-std=c++11 -pthread
SOURCES=main.cpp socket.cpp 	# y más .cpp
EXECUTABLE=talk2

talk:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)	    # Va con tabulador
	
debug:
	$(CC) -ggdb3 $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)  # Va con tabulador

clean:
	rm -rf talk2