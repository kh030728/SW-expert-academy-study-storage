#include <iostream>
using namespace std;
int main(void)
{
    for(int testcase_i=1;testcase_i<=10;testcase_i++)
    {
        int N;
        scanf("%d", &N);
        int ans[10], tmp;
        for(int i=0;i<N;i++)
        {
            if(i<10)
            {
                scanf("%d", &ans[i]);
            }
            else
            {
                scanf("%d", &tmp);
            }            
        }
        scanf("%d", &N);
        char gar;
        int start=0, command=0;
        for(int i=0;i<N;i++)
        {
            scanf(" %c %d %d", &gar, &start, &command);            
            for(int j=9;j>=start;j--)
            {
                if(j+command < 10)
                {
                    ans[j+command]=ans[j];
                }                
            }
            for(int j=0;j<command;j++)
            {
                if(start+j < 10) scanf("%d", &ans[start+j]);
                else scanf("%d", &tmp);
            }
        }
        printf("#%d ", testcase_i);
        for(int i=0;i<9;i++)
        {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[9]);
    }
    return 0;
}