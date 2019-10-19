OBJS 	= main.o hash.o read_functions.o point.o functions.o metrics.o h.o
CC		= g++
CFLAGS  = -Wall -g
TARGET = lsh

.PHONY : all
all: $(TARGET) 

lsh: $(OBJS)
	$(CC) $(CFLAGS) -o lsh $(OBJS)

main.o: src/main.cpp include/read_functions.h include/hash.h include/point.h include/functions.h
	$(CC) $(CFLAGS) -c src/main.cpp

read_functions.o: src/read_functions.cpp include/point.h
	$(CC) $(CFLAGS) -c src/read_functions.cpp

hash.o: src/hash.cpp 
	$(CC) $(CFLAGS) -c src/hash.cpp

point.o: src/point.cpp
	$(CC) $(CFLAGS) -c src/point.cpp

h.o: src/h.cpp
	$(CC) $(CFLAGS) -c src/h.cpp

metrics.o: src/metrics.cpp
	$(CC) $(CFLAGS) -c src/metrics.cpp

functions.o: src/functions.cpp include/metrics.h
	$(CC) $(CFLAGS) -c src/functions.cpp

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

	  

