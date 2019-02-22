CC=g++
CFLAGS=
LDLIBS=

all: program

program: main.o convert.o 
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	
main.o: main.cpp main.h convert.h
	$(CC) $(CFLAGS) -c $< -o $@

convert.o: convert.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	-rm *.o $(objects)