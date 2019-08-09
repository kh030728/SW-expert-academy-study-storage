#include<iostream>
#include <queue>
#include <string>
using namespace std;

int main(void)
{
    int test=0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        int N = 0;
        scanf("%d", &N);
        string tmp;
        queue<string> a, b;
        int change = N/2;
        if(N%2 == 1)  change++;
        for(int i=1;i<=N;i++)
        {
            cin >> tmp;
            if(i <= change) a.push(tmp);
            else b.push(tmp);
        }
        printf("#%d ", test_i);
        while(!a.empty())
        {
            cout << a.front() <<" ";
            a.pop();
            if(!b.empty()) {
                cout << b.front() << " ";
                b.pop();
            }
        }
        printf("\n");
    }
    

}