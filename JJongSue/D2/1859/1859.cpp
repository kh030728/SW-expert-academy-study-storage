#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(void)
{
    int test=0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++){
        int N=0;
        scanf("%d", &N);
        vector <int> b(N,0);
        vector <int> max(N,0);
        for(int i=0;i<N;i++){
            scanf("%d", &b[i]);
            for(int j=0;j<i;j++)
            {
                if( b[i]-b[j] > max[j] ) max[j]=b[i]-b[j];
            }
        }
        
        long long ans = 0;
        for(int i=0;i<N;i++)
        {
            ans+=max[i];
        }
        printf("#%d %lld\n", test_i, ans);

    }
    return 0;
}