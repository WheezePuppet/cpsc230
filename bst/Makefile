
bst: main.o BST.o LL.o
	g++ -o bst main.o BST.o LL.o

main.o: main.cpp BST.h LL.h
	g++ -c main.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp

LL.o: LL.cpp LL.h
	g++ -c LL.cpp

