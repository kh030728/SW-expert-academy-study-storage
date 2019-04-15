#include <iostream>
#include <cmath>
using namespace std;

/*********************************************************
 * 함수 : exec
 * 인자 : long long N
 * 반환 : int
 * 기능 : 문제에 설명된 제곱근 규칙에 따라 동작하도록
 * 제작되었다. 계산에서 N이 2보다 클 때 규칙에 따라
 * 동작하고, 제곱근이 정수가 아닌 경우 해당 제곱근에서
 * 정수 부분을 추출해 1을 더해준후 제곱해준다. 그 후 N
 * 과의 차이를 count에 더해줌으로써 연산량을 줄일 수 있다.
 ********************************************************/
 
int exec(long long N) 
{
    int count = 0; int tmp;
    double dp;
    while(N > 2) 
    {
        dp = sqrt(N);
        tmp = (int) dp;
        if(dp == tmp) { N = dp; count++; }
        else { count += (pow(tmp+1, 2) - N +1); N = tmp+1; }
    }
    return count;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;      
    long long N = 0;

    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >>N;
        cout <<"#"<<test_case<<" "<< exec(N) << endl;
    }
    return 0;
}