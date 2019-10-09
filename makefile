OBJS 	= read_functions.o main.o
CC		= g++
CFLAGS  = -Wall -g
TARGET = lsh

.PHONY : all
all: $(TARGET) 

lsh: $(OBJS)
	$(CC) $(CFLAGS) -o lsh $(OBJS)

main.o: src/main.cpp include/read_functions.h
	$(CC) $(CFLAGS) -c src/main.cpp

read_functions.o: src/read_functions.cpp
	$(CC) $(CFLAGS) -c src/read_functions.cpp

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

	  

