#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int test;
    scanf("%d", &test);
    for (int test_i = 1; test_i <= test; test_i++)
    {
        int N, D, tmp, answer = 0;
        ;

        scanf("%d %d", &N, &D);

        if (N == 1)
        {
            scanf("%d", &tmp);
            if (tmp == 1)
                printf("#%d 0\n", test_i);
            else
                printf("#%d 1", test_i);
        }
        else
        {
            vector<int> road(N, 0);
            for (int i = 0; i < N; i++)
            {
                scanf(" %d", &road[i]);
            }
            if (road[0] != 1)
            {
                answer++;
                road[0] = 1;
            }
            int cnt = 1;
            for (int i = 0; i < N; i++)
            {
                if (cnt < D)
                {
                    if(road[i] ==1) cnt=1;
                    else{
                        cnt++;
                    }
                }
                else
                {
                    if (road[i] == 1)
                    {
                        cnt = 1;
                    }
                    else
                    {
                        cnt=1;
                        answer++;
                    }
                }
            }
            printf("#%d %d\n", test_i, answer);
        }
    }
    return 0;
}