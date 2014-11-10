
jumble: jumble.o PermutationGenerator.o Dictionary.o
	g++ -o jumble jumble.o PermutationGenerator.o Dictionary.o

jumble.o: jumble.cpp Dictionary.h utils.h
	g++ -c jumble.cpp

PermutationGenerator.o: PermutationGenerator.cpp utils.h
	g++ -c PermutationGenerator.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

