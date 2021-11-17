//Start Time	: 0920
//End Time		: 
//통과 유뮤		: 1트 테스트만 통과 0957 | 3트 통과 1038

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

#define Score int
#define Index int
using namespace std;

// 0920 
//

#pragma region FirstSolution
int CalcScore(vector<int> Cur, vector<int> Next, int* piScore ,int iPreIndex = -1)
{
	int iScoreTemp = 0;
	int iCurIndex = 0;

	if (iPreIndex == -1)
	{
		for (int i = 0; i < (int)Cur.size(); ++i)
		{
			for (int k = 0; k < (int)Next.size(); ++k)
			{
				if (i == k)
				{
					continue;
				}
				else 
				{
					if (*piScore < Cur[i] + Next[k])
					{
						*piScore = Cur[i] + Next[k];
						iCurIndex = k;
					}
				}
			}
		}

		return iCurIndex;
	}
	else 
	{
		for (int k = 0; k < (int)Next.size(); ++k)
		{
			if (iPreIndex == k)
			{
				continue;
			}
			else
			{
				if (iScoreTemp < *piScore + Next[k])
				{
					iScoreTemp = *piScore + Next[k];
					iCurIndex = k;
				}
			}
		}

		*piScore = iScoreTemp;
		return iCurIndex;
	}

	

}

int Fisrtsolution(vector<vector<int> > land)
{
	int answer = 0;

	int PreIndex = -1;
	
	for (int i = 0; i < (int)land.size()-1; ++i)
	{
		PreIndex = CalcScore(land[i], land[i + 1], &answer, PreIndex);
	}

	return answer;
}
#pragma endregion

#pragma region SecondSolution
//어차피 우리가 결국 필요한건 최고 값만 필요함. 
//특정 행의 각 원소에서 전 행의 자신과 같은 열을 제외하고 다 더해 봤을 때 
//그 중 가장 큰 값을 배열로 기억하고 있자.
//그 다음 행 차례에서 
//방금 위에 단계로 인해 업데이트 된 최대값 배열과 또 비교 한 뒤 최대값을 뽑고
//쭊쭊 이어나가다 보면 결국 마지막으로 나오는 배열은 
//각 행의 원소들이 그 전의 행과의 모든 경우의 수 중 가장 큰 수들을 모아둔 것이기 때문에
//거기서 가장 큰 값을 가져오면 됨.
//어떻게 보면 내가 원래 짯던거 보다 더 구현하기에는 간단한 로직이지만,
//생각해내기가 디게 어렵네
//이렇게 푸는걸 DP => Dynamic Programing 이라는데
//그냥 똒똑한거인듯

void CalcScore(vector<int>& _MaxVal, vector<int> _CurVal)
{
	vector<int> Temp;
	vector<int> OriginVector = _MaxVal;

	if (_MaxVal.size() == 0)
	{
		for (int i = 0; i < _CurVal.size(); ++i)
		{
			_MaxVal.emplace_back(_CurVal[i]);
		}
	}
	else
	{
		for (int i = 0; i < _CurVal.size(); ++i)
		{
			for (int k = 0; k < _CurVal.size(); ++k)
			{
				if (i == k)
				{
					continue;
				}
				else
				{
					Temp.emplace_back(_CurVal[i] + OriginVector[k]);
				}
			}

			int iMax = *(max_element(Temp.begin(), Temp.end()));
			_MaxVal[i] = iMax;
			Temp.clear();
		}

	}

}

int solution(vector<vector<int>> land)
{
	int answer = 0;

	vector<int> vecMaxValues;

	for (int i = 0; i < land.size(); ++i)
	{
		CalcScore(vecMaxValues, land[i]);
	}

	answer = *max_element(vecMaxValues.begin(), vecMaxValues.end());

	return answer;
}

int Othersolution(vector<vector<int> > land)
{
	//기존의 vector를 임시 저장소로 이용하면서 더욱 간단하게 표현 한것.
	//어차피 한 행의 원소 개수는 정해져 있으니까~
	for (int i = 0; i < land.size() - 1; i++)
	{
		land[i + 1][0] += max(land[i][1], max(land[i][2], land[i][3]));
		land[i + 1][1] += max(land[i][0], max(land[i][2], land[i][3]));
		land[i + 1][2] += max(land[i][1], max(land[i][0], land[i][3]));
		land[i + 1][3] += max(land[i][1], max(land[i][2], land[i][0]));
	}

	return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}
#pragma endregion





void main()
{

	vector<vector<int>> temp = { {{1,2,3,5},{5,6,7,8},{4,3,2,1}} };

	solution(temp);

	system("pause");
}