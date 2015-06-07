#pragma once
#include "AbstractGenerator.h"

template <typename T>
class PermutationsGenerator :
	public AbstractGenerator<T>
{
public:

	PermutationsGenerator(std::vector<T> &base, bool COMPARE_FLAG = false, bool ONE_TRANSPOSITION_GENERATE = false)
	{
		if (base.size() > MAX_SIZE)	throw MAX_SIZE_EXCEPTION;
		_base = base;
		_COMPARE_FLAG = COMPARE_FLAG;

		if (!ONE_TRANSPOSITION_GENERATE) generate();
		else oneTranspositionGenerate();
	}

	~PermutationsGenerator()
	{

	}

	std::vector<T> getPermutation(int index)
	{
		if (index < 0 && index >= _result.size) throw INTEGER_PERMUTATIONS_GENERATOR_GET_PERMUTATION_INDEX_EXCEPTION;

		return _result[index];
	}

	int getNumber(std::vector<T> permunation)
	{
		if (permunation.size() != _base.size()) throw PERMUTATIONS_GENERATOR_GET_NUMBER_PERMUTATION_SIZE_EXEPTION;

		if (!_COMPARE_FLAG)	throw PERMUTATIONS_GENERATOR_GET_NUMBER_COMPARE_EXEPTION;

		int left = 0;
		int right = _result.size();
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;

			bool more = false;
			bool less = false;

			for (int i = 0; i < permunation.size() && (more == less); i++)
			{
				if (_result[mid][i] < permunation[i])
				{
					less = true;
					right = mid - 1;
				}
				else if (_result[mid][i] > permunation[i])
				{
					more = true;
					left = mid + 1;
				}
			}
		}
		return mid;
	}

protected:

	bool _COMPARE_FLAG; //можно ли сравнивать элементы множества?

	PermutationsGenerator(){ }
	
	virtual void generate()
	{
		//можно сравнивать элементы, а значит, можно предотвратить повторы
		if (_COMPARE_FLAG)
		{
			//найти первую перестановку
			while (prev_permutation(_base.begin(), _base.end()));
			if (_base[0] > _base.size()-1)
			{
				next_permutation(_base.begin(), _base.end());
			}

			//генерация всех перестановок (в лексикографическом порядке)
			_result.push_back(_base);
			while (next_permutation(_base.begin(), _base.end()))
			{
				_result.push_back(_base);
			}
		}
		//перестановка с помощью ассоциируемых индексов
		else
		{
			_result.push_back(_base);

			//получить индексы
			std::vector<unsigned int> indexes;
			for (int i = 0; i < _base.size(); i++)
			{
				indexes.push_back(i);
			}

			while (next_permutation(indexes.begin(), indexes.end()))
			{
				std::vector<T> v;

				for (int i = 0; i < indexes.size(); i++)
				{
					v.push_back(_base[indexes[i]]);
				}

				_result.push_back(v);
			}
		}
	}

	void oneTranspositionGenerate()
	{
		//получить индексы
		/*std::vector<int> indexes;
		for (int i = 0; i < _base.size(); i++)
		{
			indexes.push_back(i);
		}

		for (int i = 0; i < indexes.size(); i++)
		{
			for (int j = i+1; j < _base.size(); j++)
			{
				std::vector<T> buffer = indexes;
				//транспозиция
				buffer[i] = j;
				buffer[j] = i;

				std::vector<T> permutation;
				for (int k = 0; k < _base.size(); k++)
				{
					permutation.push_back(_base[indexes[k]]);
				}
				_result.push_back(permutation);
			}
		}

		*/

		std::vector<T> base = _base;
		for (int i = base.size()-1; i >= 0; i--)
		{
			for (int j = i-1; j >= 0; j--)
			{
				T temp = base[i];
				base[i] = base[j];
				base[j] = temp;
				_result.push_back(base);
				base = _base;
			}
		}
	}
};