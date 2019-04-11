#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
        cin>>N>>K;
        vector<int> level(N,0);
        for(int i=0; i<N; i++){		//입력 받기
            int tmp;
            cin>>tmp;
            level[i] = tmp;
        }
		sort(level.begin(), level.end(), greater<int>());
		double sum = 0;
        for(int i=K-1; i>=0; i--)
        {
            sum = (sum + level[i])/2;
        }
        printf("#%d %.6f\n", test_case, sum);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}