OBJS 	= main.o hash.o read_functions.o point.o main_functions.o metrics.o h.o hashtable.o print_functions.o
CC		= g++
CFLAGS  = -Wall -g
TARGET = lsh

.PHONY : all
all: $(TARGET) 

lsh: $(OBJS)
	$(CC) $(CFLAGS) -o lsh $(OBJS)

main.o: src/main.cpp include/read_functions.h include/point.h include/main_functions.h include/hashtable.h include/defines.h include/print_functions.h
	$(CC) $(CFLAGS) -c src/main.cpp

read_functions.o: src/read_functions.cpp include/point.h include/defines.h
	$(CC) $(CFLAGS) -c src/read_functions.cpp

hashtable.o: src/hashtable.cpp include/hash.h
	$(CC) $(CFLAGS) -c src/hashtable.cpp	

hash.o: src/hash.cpp include/h.h
	$(CC) $(CFLAGS) -c src/hash.cpp

point.o: src/point.cpp
	$(CC) $(CFLAGS) -c src/point.cpp

h.o: src/h.cpp
	$(CC) $(CFLAGS) -c src/h.cpp

metrics.o: src/metrics.cpp
	$(CC) $(CFLAGS) -c src/metrics.cpp

main_functions.o: src/main_functions.cpp include/metrics.h
	$(CC) $(CFLAGS) -c src/main_functions.cpp

print_functions.o: src/print_functions.cpp 
	$(CC) $(CFLAGS) -c src/print_functions.cpp

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

	  

