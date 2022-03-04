//Start Time	: 0907
//End Time		: 0920
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;


int solution(int n)
{
	int answer = 0;

	vector<int> vecFibo = { 0, 1 };

	for (int i = 2; i <= n; ++i)
	{
		vecFibo.emplace_back((vecFibo[i - 1] + vecFibo[i - 2]) % 1234567);
	}

	answer = vecFibo[n];


	return answer;
}

void main()
{


	system("pause");
}