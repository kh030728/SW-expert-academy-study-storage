#include <iostream>
#include <queue>

static int num[7];

using namespace std;
int main(void)
{
    int test =0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        priority_queue<int> pq;
        for(int i=0;i<7;i++){
            scanf("%d", &num[i]);
        }
        bool jung[601] = {false, };
        for(int i=0;i<5;i++)
        {
            for(int j=i+1;j<6;j++)
            {
                for(int k=j+1;k<7;k++)
                {
                    int x = num[i]+num[j]+num[k];
                    if(jung[x]==false)
                    {
                        pq.push(x);
                        jung[x]=true;
                    }
                    
                }
            }
        }

        pq.pop();
        pq.pop();
        pq.pop();
        pq.pop();
        
        printf("#%d %d\n", test_i, pq.top());
    }

    return 0;
}