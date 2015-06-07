#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

#include "GlobalDefines.h"

using namespace std;

template <typename T>
class AbstractGenerator
{
public:
	AbstractGenerator()
	{
		
	}
	virtual ~AbstractGenerator()
	{
	
	}

	std::vector< std::vector<T> > getResult()
	{
		return _result;
	}

protected:

	std::vector< std::vector<T> > _result;
	std::vector<T> _base;

	virtual void generate() = 0;

};

