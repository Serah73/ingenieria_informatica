# definimos las siguientes variables:
# C++: indicará el compilador a usar
# C++.FLAGS: indica las opciones del compilador, en este caso -g para depuración
C++ = g++
SOURCES = $(wildcard *.cpp)
# regla para compilar cualquier fichero .cpp
# $^: variable automática de make que contiene todos los PREREQUISITES
# $@: variable automática de make que contiene el nombre del TARGET
test: $(SOURCES)
	$(C++) $^ -o $@