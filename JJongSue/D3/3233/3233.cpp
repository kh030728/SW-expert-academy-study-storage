#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    long long T = 0;
    scanf("%lld", &T);
    vector<unsigned long long> tri(1000001, 0);
    vector<unsigned long long>triarr(1000001,0);
    
    tri[1] = 1;
    triarr[1] = 1;
    for(int i=2;i<=1000000;i++)
    {
        tri[i] = tri[i-1] + 2;
        triarr[i] = tri[i] + triarr[i-1];
    }
    //printf("%u\n", triarr[1000000]);
    //test case숫자 입력
    //삼각형A, 삼각형B의 길이 입력 기후 내부 삼각형 갯수 리턴

    for(int test_i=1;test_i<=T;test_i++)
    {
        long long A, B;
        long long C = 1000000;
        scanf("%lld %lld", &A, &B);
        //printf("%lld %lld %lld\n", A, B, A/B);
        printf("#%d %llu\n", test_i,triarr[A/B]);
    }
    
    return 0;
}