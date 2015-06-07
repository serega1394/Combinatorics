#include "stdafx.h"
#include "IntegerPermutationsGenerator.h"


IntegerPermutationsGenerator::IntegerPermutationsGenerator(std::vector<int> base, bool ONE_TRANSPOSITION_GENERATE) : PermutationsGenerator(base, true, ONE_TRANSPOSITION_GENERATE)
{
}
IntegerPermutationsGenerator::IntegerPermutationsGenerator(int N, int first)
{
	if (N > MAX_SIZE)	throw MAX_SIZE_EXCEPTION;

	if (N < 1)	throw INTEGER_PERMUTATIONS_GENERATOR_SIZE_EXCEPTION;

	std::vector<int> base;
	int value = first;
	for (int i = 1; i <= N; i++) //цикл N раз
	{
		base.push_back(value);
		value++;
	}

	_base = base;
	_COMPARE_FLAG = true;

	generate();
}


IntegerPermutationsGenerator::~IntegerPermutationsGenerator()
{
}

void IntegerPermutationsGenerator::toFile(std::string filename)
{
	CombinatoricsOutput<int>::toFile(filename, _result);
}
