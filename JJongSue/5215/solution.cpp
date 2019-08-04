#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find_max(vector<vector<int>> &a, int limit_cal, int score, int i);
int main(void)
{
    int testcase_num;
    scanf("%d", &testcase_num);
    for (int test_iter = 0; test_iter < testcase_num; test_iter++)
    {
        vector<vector<int>> cal;
        int food = 0, limit_cal = 0;
        scanf("%d %d", &food, &limit_cal);
        for (int i = 0; i < food; i++)
        {
            vector<int> tmp;
            int a = 0, b = 0;
            scanf("%d %d", &a, &b);
            if (a <= limit_cal)
            {
                tmp.push_back(a);
                tmp.push_back(b);
                cal.push_back(tmp);

                /* cal[i].push_back(a);
                cal[i].push_back(b);*/
            }
        }
        int answer = find_max(cal, limit_cal, 0, 0);
        if (answer == -1)
            answer = 0;
        printf("#%d %d\n", test_iter+1, answer);
    }
}

int find_max(vector<vector<int>> &a, int limit_cal, int score, int i)
{
    printf("find max %d %d\n", limit_cal, score);
    if (a.size() == i)
    {
        if (limit_cal < 0)
            return score - a[i - 1][0];
        else
            return score;
    }
    else
    {
        if (limit_cal == 0)
            return score;
        else if (limit_cal < 0)
            return score - a[i - 1][0];
        else
        {
            return max(find_max(a, limit_cal, score, i + 1), find_max(a, limit_cal - a[i][1], score + a[i][0], i + 1));
        }
    }
}