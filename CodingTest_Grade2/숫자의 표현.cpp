//Start Time	:0750
//End Time		: 0757
//통과 유뮤		: 의도치 않은 1트 성공

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int n)
{
	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		int iTemp = i;
		int iOrigin = n;

		while (true)
		{
			iOrigin -= iTemp;

			if (iOrigin == 0)
			{
				++answer;
				break;
			}

			if (iOrigin < 0)
			{
				break;
			}

			++iTemp;
		}

	}

	return answer;
}

void main()
{


	system("pause");
}