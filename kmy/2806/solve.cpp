#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int cnt = 0;
bool check(int y, vector<short> chess, int N)
{
	int x = chess[y];
	for (int i = y-1; i >= 0; i--)
	{
		int a = chess[i];
		if (x == a || (abs(x - a) == (y - i)))
			return false;
	}
	return true;
}
bool dfs(int y, vector<short> chess, int N)
{
	if (y == N - 1) {
		cnt++;
		return true;
	}
	for (int i = 0; i<N; i++)
	{
		chess[y+1] = i;
		if(check(y + 1, chess, N))
			dfs(y + 1, chess, N);
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
		vector<short> tmp(N, -1);

		cnt = 0;
		int aa = 0;
		for (int i = 0; i < N; i++) {
			tmp[0] = i;
			dfs(0, tmp, N);

		}
		printf("#%d %d\n", test_case, cnt);

	}
	return 0;
}