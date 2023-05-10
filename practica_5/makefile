CC=g++
CFLAGS=-c -Wall -std=c++11 -Iinclude
EXEC=rpn
LDFLAGS=
SOURCES=$(wildcard src/*.cc)
OBJECTS=$(addprefix build/, $(notdir $(SOURCES:.cc=.o)))

all: build/ $(EXEC)

build/:
	mkdir -p build

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

build/%.o: src/%.cc
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXEC)
