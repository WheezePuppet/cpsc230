
run: playWithStack
	./playWithStack

playWithStack: playWithStack.o StackLL.o
	g++ -o playWithStack playWithStack.o StackLL.o

playWithStack.o: playWithStack.cpp StackLL.h
	g++ -c playWithStack.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

StackLL.o: StackLL.cpp StackLL.h
	g++ -c StackLL.cpp
