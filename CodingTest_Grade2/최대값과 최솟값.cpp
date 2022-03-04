//Start Time	: 0855
//End Time		: 0910
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string s)
{
	string answer = "";

	vector<int> vecInts;

	string szTemp;

	for (int i = 0; i < s.length(); ++i)
	{

		if (s[i] == ' ')
		{
			int iTemp = stoi(szTemp);
			vecInts.emplace_back(iTemp);
			szTemp = "";
		}
		else
		{
			szTemp += s[i];
		}

		if (s.length() - 1 == i)
		{
			int iTemp = stoi(szTemp);
			vecInts.emplace_back(iTemp);
		}


	}

	sort(vecInts.begin(), vecInts.end());

	int iMin = vecInts.front();
	int iMax = vecInts.back();

	answer = to_string(iMin) + " " + to_string(iMax);

	return answer;
}


void main()
{

	solution("1 2 3 4");

	system("pause");
}