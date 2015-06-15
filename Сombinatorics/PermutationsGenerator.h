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

protected:

	bool _COMPARE_FLAG; //����� �� ���������� �������� ���������?

	PermutationsGenerator(){ }
	
	virtual void generate()
	{
		_result.clear();

		//����� ���������� ��������, � ������, ����� ������������� �������
		if (_COMPARE_FLAG)
		{
			//����� ������ ������������
			while (prev_permutation(_base.begin(), _base.end()));
			if (_base[0] > _base.size()-1)
			{
				next_permutation(_base.begin(), _base.end());
			}

			//��������� ���� ������������ (� ������������������ �������)
			_result.push_back(_base);
			while (next_permutation(_base.begin(), _base.end()))
			{
				_result.push_back(_base);
			}
		}
		//������������ � ������� ������������� ��������
		else
		{
			IntegerPermutationsGenerator *ipg = new IntegerPermutationsGenerator(_base.size(), 0);
			//ipg->generate();
			std::vector<std::vector<int>> indexesResult = ipg->getResult(); //�������� ������������ ��������

			_result.push_back(_base);

			for (int i = 0; i < indexesResult.size(); i++)
			{
				std::vector<T> A;
				for (int j = 0; j < indexesResult[i].size(); j++)
				{
					A.push_back(_base[indexesResult[i][j]]);
				}
				_result.push_back(A);
			}
		}
	}

	void oneTranspositionGenerate()
	{
		//�������� �������
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
				//������������
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

		if (_COMPARE_FLAG)
		{
			std::vector<T> base = _base;
			for (int i = base.size() - 1; i >= 0; i--)
			{
				for (int j = i - 1; j >= 0; j--)
				{
					T temp = base[i];
					base[i] = base[j];
					base[j] = temp;
					_result.push_back(base);
					base = _base;
				}
			}
		}
		else
		{

		}
	}
};