CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main_maze_t.cpp maze_t.cpp 
HEADERS=maze_t.hpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main_maze_t

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
    
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
