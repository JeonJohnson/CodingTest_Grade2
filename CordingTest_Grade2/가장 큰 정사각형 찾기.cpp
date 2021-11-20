//1221
//1314 debuging via vs
//1326 TestCase Pass, Submit Case no.8 cant pass & All Efficiency Test Cant Pass  grade : 56.5
//1332 Submit Case no8 pass, Efficiency test cant pass all

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
int solution(vector<vector<int>> board)
{
	int answer = 1234;

	int iRowSize = board.size();
	int iColSize = board.front().size();

	int iMaxRange = 0;
	iRowSize <= iColSize ? iMaxRange = iRowSize : iMaxRange = iColSize;

	int iCount = 0;

	for (int i = iMaxRange; i > 0; --i)//확인할 범위 줄여가는거
	{
		for (int k = 0; k <= iColSize - i; ++k) //column 시작지점
		{
			if (k + i > iColSize)
			{
				continue;
			}

			for (int j = 0; j <= iRowSize - i; ++j) //Row 시작지점
			{
				if (j + i > iRowSize)
				{
					continue;
				}

				for (int o = k; o < k + i; ++o)//column에서 확인할 범위
				{
					for (int p = j; p < j + i; ++p)
					{
						if (board[p][o] == 1)
						{
							++iCount;
						}
					}
				}

				if (iCount == pow(i, 2))
				{
					return iCount;
				}
				else { iCount = 0; }
			}
		}
	}
	
	return iCount;
}


void main()
{
	//vector<vector<int>> temp = {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}};
	vector<vector<int>> temp = {{0, 0, 1, 1}, {1, 1, 1, 1}};
	solution(temp);

	system("pause");
}