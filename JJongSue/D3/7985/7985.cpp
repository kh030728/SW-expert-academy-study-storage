#include <iostream>
#include <queue>
#include <vector>
vector<int> num;
using namespace std;
int main(void)
{
    int test = 0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        int N=0,tmp=0, range=0;
        scanf("%d", &N);
        vector<queue<int>> vq(N, queue<int>());
        queue<int> last;
        range=1;
        for(int i=0;i<N;i++)
            range*=2;
        num.assign(range,0);
        for(int i=0;i<range;i++)
        {
            scanf("%d", &num[i]);
        }
        for(int i=0;i<=N;i++)
        {
            for(int j=1;j<=(1<<i);j++)
            {
                
            }
        }
        
        for(int i=0;i<N;i++)
        {
            range+=(1<<i);
        }        
        for(int i=1;i<=range;i++)
        {
            bool is_last=true;
            scanf("%d", &tmp);
            for(int j=1;j<N;j++)
            {
                if(i == ((range+1)%(1<<j)) )
                {
                    is_last=false;
                    vq[j-1].push(tmp);
                    break;
                }                
            }
            if(is_last) last.push(tmp);
        }
        printf("#%d ", test_i);
        for(int i=0;i<N;i++)
        {
            while(!vq[i].empty())
            {
                printf("%d ", vq[i].front());
                vq[i].pop();                
            }
            printf("\n");
        }
        while(!last.empty())
        {
            printf("%d ", last.front());
            last.pop();
        }
        printf("\n");
    }   
    return 0;
}
void dfs(int first, int second)
{
    printf("%d", num[(first+second)/2]);
    
}