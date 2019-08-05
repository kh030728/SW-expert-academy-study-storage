#include <iostream>
#include <vector>
using namespace std;
static vector<vector<int>> code;
int findcode(int x, int y);
int main(void)
{
    int testcase_num = 0;
    scanf("%d", &testcase_num);
    for (int test_i = 1; test_i <= testcase_num; test_i++)
    {

        int N = 0, M = 0;
        code.clear();
        scanf("%d %d", &N, &M);

        code.assign(N, vector<int>(M, 0));
        bool find = true;
        int f = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%1d", &code[i][j]);
            }
        }
        int cnt = 0;
        int a[8];
        bool end = false;
        int sum = 0, answer = 0;
        for (int k = 0; k < M; k++)
        {
            if (end == true)
                break;
            cnt = 0;
            for (int i = 0; i < N; i++)
            {
                cnt = 0;
                if (end == true)
                    break;
                for (int j = 6 + k; j < M; j++)
                {
                    if (code[i][j] == 1)
                    {
                        int tmp = findcode(j - 6, i);
                        if (tmp != -1)
                        {
                            a[cnt] = tmp;
                            cnt++;
                            j = j + 6;
                            if (cnt >= 8)
                            {
                                end = true;
                                break;
                            }
                        }
                        else cnt=0;
                    }
                }
            }
        }

        
        for (int i = 0; i < 8; i++)
        {
            answer += a[i];
            if ((i + 1) % 2 == 1)
                a[i] = a[i] * 3;
            sum += a[i];
        }
        if (sum % 10 != 0)
            printf("#%d 0\n", test_i);
        else
            printf("#%d %d\n", test_i, answer);
    }
    return 0;
}
int findcode(int x, int y)
{
    int a = 0, b = 0, c = 0, d = 0;
    int i = 0, j = 0;

    for (i = 0; i < 7; i++)
    {
        if (code[y][x + i] == 0)
            a++;
        else
            break;
    }
    for (j = i; j < 7; j++)
    {
        if (code[y][x + j] == 1)
            b++;
        else
            break;
    }
    for (i = j; i < 7; i++)
    {
        if (code[y][x + i] == 0)
            c++;
        else
            break;
    }
    for (j = i; j < 7; j++)
    {
        if (code[y][x + j] == 1)
            d++;
        else
            break;
    }
    if (a == 3 && b == 2 && c == 1 && d == 1)
        return 0;
    if (a == 2 && b == 2 && c == 2 && d == 1)
        return 1;
    if (a == 2 && b == 1 && c == 2 && d == 2)
        return 2;
    if (a == 1 && b == 4 && c == 1 && d == 1)
        return 3;
    if (a == 1 && b == 1 && c == 3 && d == 2)
        return 4;
    if (a == 1 && b == 2 && c == 3 && d == 1)
        return 5;
    if (a == 1 && b == 1 && c == 1 && d == 4)
        return 6;
    if (a == 1 && b == 3 && c == 1 && d == 2)
        return 7;
    if (a == 1 && b == 2 && c == 1 && d == 3)
        return 8;
    if (a == 3 && b == 1 && c == 1 && d == 2)
        return 9;
    return -1;
}