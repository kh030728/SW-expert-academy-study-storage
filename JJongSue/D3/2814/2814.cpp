#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int test_i = 1; test_i <= T; test_i++)
    {
        int N, M;
        scanf("%d %d", &N, &M);
        vector<vector<bool>> map(N, vector<bool>(N, false));
        for (int i = 0; i < M; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            map[x - 1][y - 1] = true;
            map[y - 1][x - 1] = true;
        }
        if (M == 0)
        {
            printf("#%d 1\n", test_i);
            continue;
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int cnt = 1;
            vector<bool> is_visit(N, false);
            is_visit[i] = true;
            stack<int> savenum;
            savenum.push(i);
            while (!savenum.empty())
            {
                int tmp = savenum.top();
                savenum.pop();
                for (int j = 0; j < N; j++)
                {
                    if (map[tmp][j] && is_visit[j]==false)
                    {
                        savenum.push(j);
                        is_visit[j]=true;
                        cnt++;
                    }
                }
                if(ans < cnt) ans = cnt;
                cnt--;
                is_visit[tmp]=false;
            }
        }
        printf("#%d %d\n", test_i, ans);
    }
    return 0;
}