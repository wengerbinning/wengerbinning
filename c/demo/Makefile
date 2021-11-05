all: helloworld stdio

helloworld: helloworld.o
	gcc -o helloworld helloworld.o

file_manager/file_fopen: stdio
	gcc -o file_manager/file_fopen file_manager/file_fopen.o

.PHONY: clean

clean:

	rm -rf *.o
	rm helloworld
