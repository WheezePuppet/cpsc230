
run: playWithStack
	./playWithStack

playWithStack: playWithStack.o Stack.o
	g++ -o playWithStack playWithStack.o Stack.o

playWithStack.o: playWithStack.cpp Stack.h
	g++ -c playWithStack.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp
