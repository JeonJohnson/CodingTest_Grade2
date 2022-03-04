//Start Time	: 0430
//End Time		: 0445
//통과 유뮤		: 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end(), less<int>());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < A.size(); ++i)
	{
		answer += A[i] * B[i];

	}
	
	s
	

	return answer;
}

void main()
{


	system("pause");
}