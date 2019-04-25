#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

// 가지치기가 들어 갔지만 느린 코드
int cnt = 0;
bool check(int x, int y, vector<vector<bool>> chess, int N)
{
	int tmp1 = x;
	int tmp2 = x;
	for (int i = y-1; i >= 0; i--)	//대각선 왼쪽 위를 확인하는 함수
	{
		if ((--tmp1) >= 0) {
			if (chess[i][tmp1])
				return false;
		}		
		if (++tmp2<N) {
			if (chess[i][tmp2])
				return false;
		}
		if (chess[i][x])
			return false;
	}
	return true;
}
bool dfs(int x, int y, vector<vector<bool>> chess, int N)
{
	if (y == N - 1) {
		cnt++;
		return true;
	}
	for (int i = 0; i<N; i++)
	{
		vector<vector<bool>> tmp = chess;
		tmp[y + 1][i] = true;
		if(check(i, y + 1, tmp, N))
			dfs(i, y + 1, tmp, N);
	}

}
int main()
{
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N;
		scanf("%d", &N);
		vector<bool> tmp(N, false);
		vector<vector<bool>> chess(N, tmp);
		cnt = 0;
		for (int i = 0; i < N; i++) {
			vector<vector<bool>> tmp = chess;
			tmp[0][i] = true;
			dfs(i, 0, tmp, N);

		}
		printf("#%d %d\n", test_case, cnt);

	}
	return 0;
}