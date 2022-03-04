//Start Time	: 0505
//End Time		: 0513
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string s)
{
	string answer = s;

	bool IsFirst = false;
	for (int i = 0; i < answer.length(); ++i)
	{
		if (i == 0 || answer[i - 1] == ' ')
		{
			IsFirst = true;
		}
		else { IsFirst = false; }

		IsFirst ? answer[i] = toupper(answer[i]) : answer[i] = tolower(answer[i]);

		//if (IsFirst)
		//{
		//	//if (answer[i] >= 'a' && answer[i] <= 'z')
		//	//{
		//	//	answer[i] -= 32;
		//	//}
		//	toupper(answer[i]);
		//}
		//else
		//{
		//	//if (answer[i] >= 'A' && answer[i] <= 'Z')
		//	//{
		//	//	answer[i] += 32;
		//	//}
		//	tolower(answer[i]);
		//}

	}

	
	return answer;
}

void main()
{


	system("pause");
}