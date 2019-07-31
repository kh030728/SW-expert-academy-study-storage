#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(void)
{
    int test=0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        int N=0, M=0;
        scanf("%d %d", &N, &M);
        vector<int> a(N+M+1,0);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                a[i+j]++;
            }
        }
        int max= *max_element(a.begin(), a.end());
        printf("#%d ", test_i);
        for(int i=0;i<a.size();i++)
        {
            if(max == a[i]) printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}