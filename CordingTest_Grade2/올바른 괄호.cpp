//Start Time	: 1124
//End Time		: 1133
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

bool solution(string s)
{

	vector<bool> vecCheck;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
		{
			if (i == s.length() - 1)
			{
				return false;
			}

			vecCheck.emplace_back(true);
		}
		else
		{
			if (i == 0)
			{
				return false;
			}

			if (vecCheck.size() == 0)
			{
				return false;
			}
			else
			{
				vecCheck.pop_back();
			}
		}
	}

	if (vecCheck.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void main()
{


	system("pause");
}