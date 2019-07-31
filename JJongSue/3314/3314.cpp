#include<iostream>
using namespace std;
int main(){
    int test=0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        int sum=0, tmp=0;
        for(int i=0;i<5;i++)
        {
            scanf("%d", &tmp);
            if(tmp<40) sum+=40;
            else sum+=tmp;
        }
        printf("#%d %d\n", test_i, sum/5);
    }
    return 0;
}