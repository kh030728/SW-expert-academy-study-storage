#include <iostream>
using namespace std;
int main(void)
{
    int test = 0;
    scanf("%d", &test);
    for (int test_i = 1; test_i <= test; test_i++)
    {
        int N = 0;
        scanf("%d", &N);
        int tmp = 0;
        int answer = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%1d", &tmp);
                /*if(i == N/2) {answer+=tmp;
                printf("%d %d\n", i ,j);
                }*/
                if (i < N / 2)
                {
                    if (j >= (N / 2) - i && j <= (N / 2) + i)
                    {
                        answer += tmp;
                    }
                }
                else
                { //if(i>N/2){
                    int x = (N - 1) - i;
                    if (j >= N / 2 - x && j <= N / 2 + x)
                    {
                        answer += tmp;
                    }
                }
            }
        }
        printf("#%d %d\n", test_i, answer);
    }
    return 0;
}