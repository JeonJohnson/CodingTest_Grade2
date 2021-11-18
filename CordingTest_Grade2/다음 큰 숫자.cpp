//Start Time	: 1340
//End Time		: 1400
//통과 유뮤		: 1400

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include <bitset>

using namespace std;

int EJeanSoo(int n)
{
	int iCount = 0;
	int iTemp = n;

	while (true)
	{
		int iDiv = iTemp % 2;
		iTemp /= 2;

		if (iDiv == 1)
		{
			++iCount;
		}

		if (iTemp < 1)
		{
			break;
		}
	}

	return iCount;

}

int solution(int n)
{
	int answer = 0;

	int OriginCount = EJeanSoo(n);
	int i = n + 1;


	while (true)
	{
		int iOneCount = EJeanSoo(i);

		if (iOneCount == OriginCount)
		{
			answer = i;
			break;
		}
		else
		{
			++i;
		}
	}

	return answer;
}


int OtherSolution(int n) 
{
	int num = bitset<20>(n).count();
	//bitset => 이것도 하나의 stl임.
	//0(false)와 1(true)만을 가지기 위한.
	//bitset<자리수>(변수) 
	//자리수 8, 변수 1일 경우 0000 0001

	//bitset.count() => bitset배열중 true값(1)의 개수 반환.

	while (bitset<20>(++n).count() != num);
	//개수가 같으면 멈춘다. 개수가 다를 경우에만 while문 안에 들어가니까
	return n;
}

//비트연산을 이용한 2진수 자리수 확인법
int OtherCalc(int n)
{
	int nCnt = 0;
	for (int i = 0; i < 31; i++)
	{
		if (n & (0x01 << i))
		{//1을 i만큼 shift연산(이동) 이동한 값을
			//n과 and연산을 통해 각 자리수가 1과 같은지
			//확인하는거

			//i가 0이면 0000 0001(2) 를 그대로
			//n과 and연산해서 첫번째 자리가 1인지
			//i가 1이면 0000 0001(2)를 왼쪽으로 shift한
			//0000 0010(2)와 n의 and연산으로 두번째 자리가 1인지
			nCnt++;
		}
	}
	return nCnt;
}


void main()
{


	system("pause");
}