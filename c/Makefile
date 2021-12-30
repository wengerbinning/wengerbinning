all: helloworld
	echo "This is make all."


helloworld:helloworld.o
	$(CC) -o helloworld -g helloworld.o

helloworld.o: helloworld.c
	$(CC) -o helloworld.o -c helloworld.c

clean:
	echo "This is make clean."
	rm helloworld

distclean:
	echo "This is make dist clean."
	rm commit.message

.PHONY:all clean distclean
