#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static vector<int> home;
static int N, K;
static int answer;
void solve(int now, int cnt, vector<int> ele);
void find_ans(vector<int> ele);
int main(void)
{
    int test=0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        scanf("%d %d", &N, &K);
        home.clear();
        home.assign(N,0);
        for(int i=0;i<N;i++) scanf("%d", &home[i]);
        sort(home.begin(), home.end());
        answer = 10e8;
        vector<int> first;
        solve(0,0, first);
        if(answer == 10e8) printf("#%d 0\n", test_i);
        else printf("#%d %d\n", test_i, answer);
        
    }
    return 0;
}
void solve(int now, int cnt, vector<int> ele)
{
    if(cnt == K) {
        find_ans(ele);
        return;
    }
    
    if(now == N) return;
    vector<int> tmp = ele;
    solve(now+1,cnt,tmp);
    tmp.push_back(home[now]);
    solve(now+1,cnt+1,tmp);


}
void find_ans(vector<int> ele)
{
    int min, f=0;
    for(int i=0;i<N;i++)
    {
        int min=10e8;
        for(int j=0;j<K;j++)
        {
            if( abs(home[i]-ele[j])<min ) min = abs(home[i]-ele[j]);
        }
        f += min;
    }
    if(f < answer) answer= f;
}