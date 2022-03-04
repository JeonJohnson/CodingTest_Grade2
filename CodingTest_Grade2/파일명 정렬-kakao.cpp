//Start Time	: 1136
//End Time		: 1254 => 1시간 18분
//통과 유뮤		: 1트 1251 10점| 1254 통과
//1트 3번부터 다 틀림 => sort 함수의 버그때문임 대신 stable_sort로 바꾸니 됨.

//stable_sort와 sort의 차이는?
//sort의 경우 크기가 같은(조건이 같은)원소일 경우 위치가 바뀔 위험이 있음.
//허나 stable_sort는 같은 경우 상대적 위치를 바꾸지 않는다.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string HeaderCollector(string s1)
{
	string szTemp;

	for (int i = 0; i < s1.length(); ++i)
	{
		if (s1[i] >= '0' && s1[i] <= '9')
		{
			break;
		}
		else
		{
			if (s1[i] >= 'A' && s1[i] <= 'Z')
			{
				szTemp += tolower(s1[i]);
			}
			else
			{
				szTemp += s1[i];
			}

		}
	}

	return szTemp;
}

int NumCollector(string s1)
{
	string szTemp;

	bool IsNum = false;

	for (int i = 0; i < s1.length(); ++i)
	{
		if (IsNum)
		{
			if (!(s1[i] >= '0' && s1[i] <= '9'))
			{
				break;
			}
		}

		if (s1[i] >= '0' && s1[i] <= '9')
		{
			IsNum = true;
			szTemp += s1[i];
		}
	}

	int iResult = 0;
	iResult = stoi(szTemp);

	return stoi(szTemp);
}

bool StringNumComp(string s1, string s2)
{
	int Num1;
	int Num2;

	Num1 = NumCollector(s1);
	Num2 = NumCollector(s2);

	return Num1 < Num2;

}

bool StringHeaderComp(string s1, string s2)
{
	string Header1;
	string Header2;

	Header1 = HeaderCollector(s1);
	Header2 = HeaderCollector(s2);

	//두개가 같으면 Num비교 함수로 ㄱㄱ
	if (Header1 == Header2)
	{
		return StringNumComp(s1, s2);
	}
	else
	{//오름차순 = 뒷놈이 더 크게.
		return Header1 < Header2;
		
		//내림차순 할꺼면 뒷놈이 작게 A > B 하면 됨.
	}
}


vector<string> solution(vector<string> files)
{
	vector<string> answer;

	vector<vector<string>> vecTemp;

	for (int i = 0; i < 26; ++i)
	{
		vector<string> temp;
		vecTemp.emplace_back(temp);
	}


	for (int i = 0; i < files.size(); ++i)
	{
		char szTemp = files[i].front();

		if (szTemp >= 'A' && szTemp <= 'Z')
		{
			vecTemp[szTemp - (int)('A')].emplace_back(files[i]);
		}
		else if (szTemp >= 'a' && szTemp <= 'z')
		{
			vecTemp[szTemp - (int)('a')].emplace_back(files[i]);
		}
	}

	for (int i = 0; i < (int)vecTemp.size(); ++i)
	{
		stable_sort(vecTemp[i].begin(), vecTemp[i].end(), StringHeaderComp);

		for (int k = 0; k < vecTemp[i].size(); ++k)
		{
			answer.emplace_back(vecTemp[i][k]);
		}
	}


	return answer;
}
void main()
{

	vector<string> temp
		= { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"

	};
	solution(temp);

	
	system("pause");
}