//Start Time	: 2344
//End Time		: 
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int MySolution(vector<int> arr)
{
	int answer = 0;
	
	sort(arr.begin(), arr.end());

	
	int iMin = arr.front();
	int	iFirstMin = arr.front();
	int iCount = 1;
	int iLCMCount = 0;

	while (true)
	{
		for (int i = 1; i < arr.size(); ++i)
		{
			if (arr[i] > iMin)
			{
				continue;
			}
			else 
			{
				if (iMin % arr[i] == 0)
				{
					++iLCMCount;
				}
			}
		}

		if (iLCMCount == arr.size() - 1)
		{
			answer = iMin;
			break;
		}
		else 
		{
			iLCMCount = 0;
		}

		//++iCount;
		iMin += iFirstMin;
	}

	return answer;
}

//Other Solution
int gcd(int x, int y) 
{ //최대공약수=> 유클리드 호제법.

	//return x % y == 0 ? y : gcd(y, x % y); 
	
	//위에 말을 풀어놓은것이 요거임. 
	//나머지가 0 나올때까지 계속 돌리는거.
	//while로 하거나 아니면 
	int R = x % y;

	if (R == 0)
	{
		return y;
	}
	else 
	{
		gcd(y, R);
	}

}
int lcm(int x, int y) 
{ //최소공배수 
	//=> A와B의 곱을 A와 B의 최대공약수로 나눈것과 같다.

	return x * y / gcd(x, y); 
}
int OtherSolution(vector<int> arr) 
{
	int answer = arr[0];

	for (int i = 1; i < arr.size(); i++)
	{
		answer = lcm(answer, arr[i]);
	}
	return answer;
}

void main()
{


	system("pause");
}