helloworld: helloworld.o
	gcc -o helloworld helloworld.o

helloworld.o: helloworld.c
	gcc -o helloworld.o -c helloworld.c

.PHONY: clean

clean:
	rm -rf *.o