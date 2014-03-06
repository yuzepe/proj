CC := g++
CFLAGS := -c -Wall -std=c++11
LDFLAGS := -std=c++11
SRC := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
BIN := proj

run: all
	./$(BIN)

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
