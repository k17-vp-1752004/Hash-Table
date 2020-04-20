# define compiler
CC= g++

# define compile flag
CCFLAGS= -std=c++17 -Wall -g

# define target file
TARGET= main

# define test file
TEST= test

# define object files (build from source files)
OBJ= element.o \
	hashtable.o \

# neu em muon chay file main, thi sua TARGET= main, roi test.o = main.o

# define rule to build object file (.o)
# from source file (.cpp) with header (.h)
.o: .cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY: all clean

all: $(TARGET) $(TEST)

clean:
	rm -f $(TARGET) $(TEST) *.o

# rule to run main
run: $(TARGET)
	./$(TARGET)

# rule to run test
run-test: $(TEST)
	./$(TEST) <$(data)

$(TARGET): $(OBJ) main.o
	$(CC) $(CCFLAGS) $^ -o $@

$(TEST): $(OBJ) test.o
	$(CC) $(CCFLAGS) $^ -o $@


# cai lire dau vo la standard input