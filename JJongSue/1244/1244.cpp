#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int change;
static int min1 = 0;
vector<int> number;
static vector<vector<bool>> visit;
int find_num(vector<int> N, int now, int cnt);
int main(void)
{
    int test = 0;
    scanf("%d", &test);
    for (int test_i = 1; test_i <= test; test_i++)
    {
        int N;
        min1 = 0;
        scanf("%d %d", &N, &change);
        visit.assign(change, vector<bool>(1000000, false));
        int cnt = 0;
        int tmp = N;
        number.clear();
        int iter = 0;
        while (N != 0)
        {
            number.push_back(N % 10);
            cnt++;
            N /= 10;
        }

        int ans = find_num(number, 0, cnt);
        printf("#%d %d\n", test_i, ans);
    }
}
int find_num(vector<int> N, int now, int cnt)
{
    if (now == change)
    {
        int tmp = 0;
        for (int i = cnt - 1; i >= 0; i--)
        {
            tmp = (tmp * 10) + N[i];
        }
        return tmp;
    }
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            int tmp;
            for (int j = i + 1; j < cnt; j++)
            {
                vector<int> N_1 = N;
                tmp = N_1[i];
                N_1[i] = N_1[j];
                N_1[j] = tmp;
                for (int i = cnt - 1; i >= 0; i--)
                {
                    tmp = (tmp * 10) + N_1[i];
                }
                if(visit[now][tmp]==false)
                    {
                        visit[now][tmp]=true;
                        tmp = find_num(N_1, now + 1, cnt);
                if (min1 < tmp)
                min1 = tmp;
                    }
                    else tmp=0;
                
            }
            if (min1 < tmp)
                min1 = tmp;
        }
    }
    return min1;
}