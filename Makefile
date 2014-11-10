
run: jumble
	./jumble neutron.jumble

jumble: jumble.o PermutationGenerator.o Dictionary.o puzzle.o
	g++ -o jumble jumble.o PermutationGenerator.o Dictionary.o puzzle.o

jumble.o: jumble.cpp Dictionary.h utils.h puzzle.h
	g++ -c jumble.cpp

puzzle.o: puzzle.cpp puzzle.h utils.h
	g++ -c puzzle.cpp

PermutationGenerator.o: PermutationGenerator.cpp utils.h
	g++ -c PermutationGenerator.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

