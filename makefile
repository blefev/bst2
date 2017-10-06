main: bst.o main.cpp
	g++ -o a5.out main.cpp bst.o

bst.o: bst.h bst.cpp
	g++ -o bst.o -c bst.cpp

clean:
	rm *.o
