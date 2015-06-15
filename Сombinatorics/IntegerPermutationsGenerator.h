#pragma once
#include "PermutationsGenerator.h"
#include "CombinatoricsOutput.h"
class IntegerPermutationsGenerator :
	public PermutationsGenerator < int >
{
public:
	IntegerPermutationsGenerator(std::vector<int> base, bool ONE_TRANSPOSITION_GENERATE = false);
	IntegerPermutationsGenerator(int N, int first = 1);
	~IntegerPermutationsGenerator();

	void toFile(std::string filename);

	static int getPermutationNumber(std::vector<int> permutation);

	static std::vector<int> getPermutation(int number, int n);
	
};

unsigned int factorial(unsigned int a);

