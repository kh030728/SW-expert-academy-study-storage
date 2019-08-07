#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> s;
static int N;
static int min1;
void find(int now, int cnt, vector<bool> is_visit);
int main(void)
{
    int test = 0;
    scanf("%d", &test);
    for (int test_i = 1; test_i <= test; test_i++)
    {
        min1 = 160000;
        scanf("%d", &N);
        vector<bool> is_visit(N, false);
        s.clear();
        s.assign(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &s[i][j]);
            }
        }
        find(0, 0, is_visit);
        printf("#%d %d\n", test_i, min1);
    }
    return 0;
}
void find(int now, int cnt, vector<bool> is_visit)
{

    if (cnt == N / 2)
    {
        int A = 0, B = 0;
        for (int i = 0; i < N; i++)
        {
            if (is_visit[i] == true)
            {
                for (int j = 0; j < N; j++)
                {
                    if ((is_visit[j] == true))
                    {
                        A += s[i][j];
                    }
                }
            }
            else
            {
                for (int j = 0; j < N; j++)
                {
                    if ((is_visit[j] == false))
                    {
                        B += s[i][j];
                    }
                }
            }
        }
        if (abs(A - B) < min1)
            min1 = abs(A - B);
        return;
    }
    else
    {
        if (now >= N)
            return;
        if (cnt > N / 2)
            return;
        vector<bool> is_visit2 = is_visit;
        find(now + 1, cnt, is_visit2);

        is_visit2[now] = true;
        find(now + 1, cnt + 1, is_visit2);
    }
}