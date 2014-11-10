
#ifndef UTILS_H
#define UTILS_H

#include<iostream>

void generatePermutations(std::string word, std::string permutations[]);
void printPerms(std::string word, std::ostream & os);
int fact(int n);
std::string tolower(const std::string & str);

#endif
