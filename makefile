OBJS1 	= main_lsh.o hash.o read_functions.o point.o main_functions.o metrics.o h.o hashtable_lsh.o print_functions.o
OBJS2 	= main_cube.o hash.o read_functions.o point.o main_functions.o h.o hashtable_cube.o hashtable_lsh.o print_functions.o hypercube_ht.o metrics.o f_function.o
CC		= g++
CFLAGS  = -std=c++11 -Wall -g
TARGET = lsh cube

.PHONY : all
all: $(TARGET) 

lsh: $(OBJS1)
	$(CC) $(CFLAGS) -o lsh $(OBJS1)

cube: $(OBJS2)
	$(CC) $(CFLAGS) -o cube $(OBJS2)

main_lsh.o: src/main_lsh.cpp include/read_functions.h include/point.h include/main_functions.h include/hashtable_lsh.h include/defines.h include/print_functions.h
	$(CC) $(CFLAGS) -c src/main_lsh.cpp

main_cube.o: src/main_cube.cpp include/read_functions.h include/point.h  include/main_functions.h include/hashtable_cube.h include/defines.h include/print_functions.h include/f_function.h
	$(CC) $(CFLAGS) -c src/main_cube.cpp

read_functions.o: src/read_functions.cpp include/point.h include/defines.h
	$(CC) $(CFLAGS) -c src/read_functions.cpp

hashtable_lsh.o: src/hashtable_lsh.cpp include/hash.h
	$(CC) $(CFLAGS) -c src/hashtable_lsh.cpp	

hashtable_cube.o: src/hashtable_cube.cpp include/structures.h include/f_function.h include/hashtable_cube.h
	$(CC) $(CFLAGS) -c src/hashtable_cube.cpp

hash.o: src/hash.cpp include/h.h
	$(CC) $(CFLAGS) -c src/hash.cpp
	
hypercube_ht.o: src/hypercube_ht.cpp
	$(CC) $(CFLAGS) -c src/hypercube_ht.cpp

point.o: src/point.cpp
	$(CC) $(CFLAGS) -c src/point.cpp

h.o: src/h.cpp
	$(CC) $(CFLAGS) -c src/h.cpp

metrics.o: src/metrics.cpp
	$(CC) $(CFLAGS) -c src/metrics.cpp

main_functions.o: src/main_functions.cpp include/metrics.h include/hashtable_lsh.h include/point.h
	$(CC) $(CFLAGS) -c src/main_functions.cpp

print_functions.o: src/print_functions.cpp 
	$(CC) $(CFLAGS) -c src/print_functions.cpp

f_function.o: src/f_function.cpp 
	$(CC) $(CFLAGS) -c src/f_function.cpp

.PHONY: clean
clean:
	rm -f $(OBJS1) $(OBJS2) $(TARGET)

	  

