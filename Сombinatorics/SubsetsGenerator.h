#pragma once
#include "AbstractGenerator.h"

template <typename T>
class SubsetsGenerator :
	public AbstractGenerator<T>
{
public:
	SubsetsGenerator(std::vector<T> base)
	{
		if (base.size() > MAX_SIZE)	MAX_SIZE_EXCEPTION;
		_base = base;
		generate();
	}
	~SubsetsGenerator()
	{
	
	}

	std::vector<T> _base;

protected:
	virtual void generate()
	{
		// Пустое множество
		for (int i = 0; i < pow(2,_base.size()); i++)
		{
			std::vector<unsigned int> containsFlags;
			to2SS(i, containsFlags);

			//заполинить нулями недостающие старшие разряды
			while (containsFlags.size() < _base.size())
			{
				containsFlags.insert(containsFlags.begin(), 0);
			}

			//сформировать подмножество
			std::vector<T> subset;

			for (int i = 0; i < _base.size(); i++)
			{
				if (containsFlags[i])	subset.push_back(_base[i]);
			}
			_result.push_back(subset);

		}		 
	}

	void to2SS(unsigned int value, std::vector<unsigned int> &result)
	{
		if (value)
		{
			to2SS(value >> 1, result);
			result.push_back(value & 1);
		}
	}
};

