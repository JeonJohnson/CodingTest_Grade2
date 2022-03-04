//Start Time	: 1721
//End Time		: 
//통과 유뮤		: 1800 1트 실패 | 18시 46 통
//1트 테스트는 통과인데 제출11,12,13,14,15,16,18,20,21,23,26번 57.7점 실패

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>


using namespace std;

string CalcBase(int _iBase, int _iNum)
{

	string szResult;
	int iDiv = 0;

	while (true)
	{
		iDiv = _iNum % _iBase;
		_iNum /= _iBase;

		if (iDiv >= 10)
		{
			char temp = (iDiv - 10) + 'A';
			szResult = temp + szResult;
		}
		else
		{
			szResult = to_string(iDiv) + szResult;
		}

		if (_iNum == 0)
		{
			break;
		}
	}
	return szResult;
}

string solution(int n, int t, int m, int p)
{   //n진법
	//t 미리구할 숫자의 개수 => 튜브가 말할 숫자의 개수. => 턴의 수?
	//m 게임 인원
	//p 튜브의 순서

	//현재 불러야할 숫자의 진법 구하고 
	//그거 스트링으로 뽑은다음에
	//턴 돌면서 튜브 턴에만 저장하면 될듯.
	string answer = "";

	int iCurNum = 0;
	int iPersonOrder = 1;
	int iStringIndex = 0;
	string szNumBase = CalcBase(n, iCurNum);

	while ((int)answer.length() < t)
	{
		if (iPersonOrder == p)
		{
			answer += szNumBase[iStringIndex];
		}

		++iStringIndex;
		++iPersonOrder;

		if (iPersonOrder > m)
		{
			iPersonOrder = 1;
		}

		if (iStringIndex >= szNumBase.length())
		{
			++iCurNum;
			iStringIndex = 0;
			szNumBase = CalcBase(n, iCurNum);
		}
	}

	return answer;
}


void main()
{
	solution(2, 4, 2, 1);

	system("pause");
}