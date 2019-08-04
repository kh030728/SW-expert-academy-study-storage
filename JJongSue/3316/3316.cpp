#include <iostream>
#include <string>
using namespace std;
static int N;
static string s;
int find(int now, int post_i);
int main(void)
{
    int test=0;    
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        cin >> s;
        N=s.length();
        int answer=0;
        int count = 'D'-s[0];
        printf("%d", count);
        printf("%d", 1<<count);
        for(int i=8;i<16;i++)
        {
            printf("%d\n", i>>count);
            if((i>>count)&1 ==1 )
                answer+=find(1,i);
        }
        printf("#%d %d\n", test_i, answer);
    }


    
    return 0;
}
int find(int now, int post_i){
    int answer = 0;
    if(now == N-1)
    {  
        int count = 'D'-s[now];
        for(int i=1;i<16;i++)
        {
            if( post_i&i != 0 ){
                if((i>>count)&1 == 1) return 1;
            }
        }
        return 0;
    }
    else{
        int count = 'D'-s[now];
        int answer = 0;
        for(int i=1;i<16;i++)
        {
            if( post_i&i != 0 ){
                if((i>>count)&1 == 1) {
                    answer+=find(now+1, i);
                }
            }
        }

        
    }

    return answer%1,000,000,007;
}