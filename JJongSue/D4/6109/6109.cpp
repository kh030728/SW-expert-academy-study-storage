#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(void)
{
    int test=0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        int N=0;
        scanf("%d", &N);
        string s;
        cin >> s;
        vector <vector<int>> a(N, vector<int>(N,0));
        vector <vector<int>> ans(N, vector<int>(N,0));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        if(s=="up")
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(a[i][j]==0)
                    {
                        for(int k=1;i+k<N;k++)
                        {
                            a[i+k-1][j]=a[i+k][j];
                        }
                        a[N-1][j]=0;
                    }
                }
            }            

            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    ans[i][j]=a[i][j];
                }
            }

            for(int i=1;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(a[i][j] !=0)
                    {
                        if(a[i][j] == a[i-1][j])
                        {
                            ans[i-1][j]
                        }

                    }
                    
                }
            }
        }

    }
    return 0;
}