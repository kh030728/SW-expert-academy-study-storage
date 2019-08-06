/*
문제 링크
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo

*/
#define _CRT_SECURE_NO_WARNINGS	//지움
#include <iostream>
#include <cstdio>	//지움

using namespace std;

typedef struct cell
{
	short X = 0;
	short waiting = 0;
	bool isnewcell = false;
}cell;

void multiply(cell _cont[][350], int _x, int _y)
{
	if (_cont[_y - 1][_x].X == 0)
	{//상이 빔
		_cont[_y - 1][_x].X = _cont[_y][_x].X;
		_cont[_y - 1][_x].isnewcell = true;
	}
	else if (_cont[_y - 1][_x].isnewcell && _cont[_y - 1][_x].X < _cont[_y][_x].X)
	{//상이 같은 시간에 생성됨
		_cont[_y - 1][_x].X = _cont[_y][_x].X;
	}

	if (_cont[_y][_x - 1].X == 0)
	{//좌가 빔
		_cont[_y][_x - 1].X = _cont[_y][_x].X;
		_cont[_y][_x - 1].isnewcell = true;
	}
	else if (_cont[_y][_x - 1].isnewcell && _cont[_y][_x - 1].X < _cont[_y][_x].X)
	{//좌가 같은 시간에 생성됨
		_cont[_y][_x - 1].X = _cont[_y][_x].X;
	}

	if (_cont[_y][_x + 1].X == 0)
	{//우가 빔
		_cont[_y][_x + 1].X = _cont[_y][_x].X;
		_cont[_y][_x + 1].isnewcell = true;
	}
	else if (_cont[_y][_x + 1].isnewcell && _cont[_y][_x + 1].X < _cont[_y][_x].X)
	{//우가 같은 시간에 생성됨
		_cont[_y][_x + 1].X = _cont[_y][_x].X;
	}

	if (_cont[_y + 1][_x].X == 0)
	{//하가 빔
		_cont[_y + 1][_x].X = _cont[_y][_x].X;
		_cont[_y + 1][_x].isnewcell = true;
	}
	else if (_cont[_y + 1][_x].isnewcell && _cont[_y + 1][_x].X < _cont[_y][_x].X)
	{//하가 같은 시간에 생성됨
		_cont[_y + 1][_x].X = _cont[_y][_x].X;
	}
}

int main()
{
	//M: 기본배치 가로 사이즈 N: 기본배치 세로 사이즈 K: 방치할 시간
	//cell: 배양 그릇(기본 최대사이즈 50 + 양끝 최대 150 * 2)
	int test_case, T, N, M, K, locaX, locaY, temp, result = 0;
	cell cont[350][350];
	int n, m;

	freopen("input.txt", "r", stdin);	//지움
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;

		//배열 중앙에 맞추기
		locaX = (350 / 2) - (M / 2);
		locaY = (350 / 2) - (N / 2);

		for (n = 0; n < N; n++)
		{
			for (m = 0; m < M; m++)
			{//기본 배치에 세포가 있을시 배열에 저장
				cin >> temp;
				if (temp > 0)
				{
					cont[n + locaY][m + locaX].X = temp;
				}
			}
		}

		for (int k = 0; k < K; k++)
		{
			for (n = 0; n < 350; n++)
			{
				for (m = 0; m < 350; m++)
				{
					if (cont[n][m].X > 0)
					{//cell에 세포가 있는 경우
						/*
						활성화: X == waiting
						증식: X + 1
						사망: X * 2
						*/
						if (!cont[n][m].isnewcell)
						{//이번 시간에 생기지 않은 세포인 경우
							cont[n][m].waiting++;
						}

						if (cont[n][m].waiting == (cont[n][m].X + 1))
						{//증식 타이밍
							multiply(cont, m, n);
						}

						if (cont[n][m].waiting == (cont[n][m].X * 2))
						{//사망 타이밍
							cont[n][m].X = -1;
						}
					}
				}
			}

			for (n = 0; n < 350; n++)
			{
				for (m = 0; m < 350; m++)
				{
					cont[n][m].isnewcell = false;
				}
			}
			
		}

		for (n = 0; n < 350; n++)
		{
			for (m = 0; m < 350; m++)
			{//결과 계산+초기화
				if (cont[n][m].X > 0)
				{
					result++;
				}
				cont[n][m].X = 0;
				cont[n][m].waiting = 0;
			}
		}

		cout << "#" << test_case << " " << result << endl;
		result = 0;
	}

	return 0;
}
