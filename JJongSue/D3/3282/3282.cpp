#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static int ans;
static int N, max_g;
static vector<pair<int,int>> product;
void calc(int now, int weight, int cnt);
int main(void)
{
    int T = 0;
    scanf("%d", &T);
    for(int test_i=1;test_i<=T;test_i++)
    {
        scanf("%d %d", &N, &max_g);
        ans=0;        
        product.assign(N, pair<int,int>(0,0));
        for(int i=0;i<N;i++)
        {
            scanf("%d %d", &product[i].first,&product[i].second);
        }
        //sort(product.begin(), product.end());
        calc(0,0,0);
        printf("#%d %d\n", test_i, ans);
    }
    

    
    
    return 0;
}
void calc(int now, int weight, int cnt)
{
    /*if(max_g < weight) {

        return;

    }*/
    if(cnt == N){
        if(now > ans) ans = now;
        return;
    }
    if(weight+product[cnt].first <= max_g)
    {
        calc(now+product[cnt].second, weight+product[cnt].first, cnt+1);
    }
    else{
        if(now > ans) ans = now;
    }
    calc(now, weight, cnt+1);


}