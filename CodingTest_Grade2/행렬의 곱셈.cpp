//Start Time	: 0541
//End Time		: 0648
//통과 유뮤		: 0622 안되서 구글링

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<vector<int>> answer;

	//이거 먼저 구해놓고 해야함.
	int Arr1Row = arr1[0].size();
	int Arr2Row = arr2[0].size();
	int Arr1Col = arr1.size();
	int Arr2Col = arr2.size();
	//Arr1의 로우와 Arr2 콜럼은 같다. (행렬의 곱 규칙상)
	//먼저 구해놓고 해야하는 이유
	//4x3 행렬과 3x2 행렬 곱셈시
	//두번째 for문에서 arr2[i]를 해버리면
	//i가 3일때 즉 마지막 큰 for문일때
	//arr2[3]는 없으니까 오류남.
	vector<int> vecRow;

	for (int i = 0; i < arr1.size(); ++i)
	{
	
		for (int k = 0; k < arr2[i].size(); ++k)
		{
			int iSum = 0;
			for (int j = 0; j < arr2.size(); ++j)
			{
				iSum += arr1[i][j] * arr2[j][k];
			}
			vecRow.emplace_back(iSum);
		}
		answer.emplace_back(vecRow);
		vecRow.clear();
	}


	return answer;
}


void main()
{
	

//arr1: [[1, 2, 3], [4, 5, 6]]
//
//	arr2 : [[1, 4], [2, 5], [3, 6]]
//
//	return : [[14, 32], [32, 77]]

	system("pause");
}