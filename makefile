OBJS 	= main.o hash_functions.o read_functions.o point.o 
CC		= g++
CFLAGS  = -Wall -g
TARGET = lsh

.PHONY : all
all: $(TARGET) 

lsh: $(OBJS)
	$(CC) $(CFLAGS) -o lsh $(OBJS)

main.o: src/main.cpp include/read_functions.h include/hash_functions.h include/point.h
	$(CC) $(CFLAGS) -c src/main.cpp

read_functions.o: src/read_functions.cpp include/point.h
	$(CC) $(CFLAGS) -c src/read_functions.cpp

hash_functions.o: src/hash_functions.cpp 
	$(CC) $(CFLAGS) -c src/hash_functions.cpp

point.o: src/point.cpp
	$(CC) $(CFLAGS) -c src/point.cpp

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

	  

