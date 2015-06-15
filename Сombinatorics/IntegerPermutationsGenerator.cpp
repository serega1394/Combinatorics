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

int IntegerPermutationsGenerator::getPermutationNumber(std::vector<int> permutation)
{
	int number = 1;
	for (int i = 1; i < permutation.size(); i++)
	{
		number += permutation[i - 1] * factorial(permutation.size() - i);

		if (permutation[i - 1] != permutation.size() - i + 1)
		{
			for (int j = i; j > permutation.size(); j--)
			{
				permutation[j]--;
			}
		}

	}

	return number;
}

std::vector<int> getPermutation(int number, int n)
{
	std::vector<int> result;
	bool *isUse = new bool[n];
	for (int i = 0; i < n; i++)
	{
		isUse[i] = false;
	}

	int i = 1;
	for (; i < n && number % factorial(n - i) + 1 != 0; i++)
	{
		int item = number / factorial(n - i) + 1;
		//if ()
		result.push_back(item);
		isUse[item - 1] = true;
	}
	
	result.push_back(number / factorial(n - i));
	return result;
}

unsigned int factorial(unsigned int a)
{
	// факториалы от 0 до 10 уже определены в библиотеке для повышения эффективвности работы
	if (a <= MAX_SIZE)
	{
		return FACTORIAL[a];
	}
	
	throw MAX_SIZE_EXCEPTION;
}