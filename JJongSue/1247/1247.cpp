#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;
static int N;
static int min_num;
static vector<bool> is_visit;
vector<vector<int>> distance1;
int bfs(vector<bool> is_visit2, int now, int dis);
int main(void)
{

    int test = 0;
    scanf("%d", &test);
    for (int test_i = 1; test_i <= test; test_i++)
    {
        N = 0;
        scanf("%d", &N);
        N = N + 2;
        vector<pair<int, int>> map(N, pair<int, int>(0, 0));

        distance1.assign(N, vector<int>(N, 0));
        pair<int, int> tmp;
        pair<int, int> company, home;
        scanf("%d %d", &company.first, &company.second);
        scanf("%d %d", &home.first, &home.second);
        map[0].first = company.first;
        map[0].second = company.second;
        map[N - 1].first = home.first;
        map[N - 1].second = home.second;
        for (int i = 1; i < N - 1; i++)
        {
            scanf("%d %d", &map[i].first, &map[i].second);
            //map.push_back(tmp);
            for (int j = 0; j < i; j++)
            {
                int num = abs(map[i].first - map[j].first) +
                          abs(map[i].second - map[j].second);
                distance1[i][j] = num;
                distance1[j][i] = num;
            }
        }
        for (int i = 1; i < N; i++)
        {
            int num = abs(map[i].first - map[N - 1].first) +
                      abs(map[i].second - map[N - 1].second);
            distance1[i][N - 1] = num;
            distance1[N - 1][i] = num;
        }
        is_visit.assign(N, false);
        for(int i=0;i<N-1;i++) min_num+=distance1[i][i+1];
        //min_num = 20001;
        for (int i = 1; i < N - 1; i++)
        {
            int find_num = 0;
            is_visit.assign(N, false);
            is_visit[0] = true;
            is_visit[i] = true;
            find_num += distance1[0][i];
            int x = bfs(is_visit, i, find_num);
            if (x < min_num)
                min_num = x;
        }
        printf("#%d %d\n", test_i, min_num);
    }
    return 0;
}
int bfs(vector<bool> is_visit2, int now, int dis)
{
    bool is_end = true;
    if (min_num <= dis)
        return min_num;
    for (int i = 1; i < N - 1; i++)
    {
        if (is_visit2[i] == false)
        {
            is_end = false;
            vector<bool> is_visit3 = is_visit2;
            is_visit3[i] = true;
            if (dis + distance1[now][i] < min_num)
            {
                int x = bfs(is_visit3, i, dis + distance1[now][i]);
                if (x < min_num)
                {
                    min_num = x;
                }
            }
        }
    }
    
    if (is_end)
    {
        return dis + distance1[N - 1][now];
    }
    else
    {
        return min_num;
    }
}