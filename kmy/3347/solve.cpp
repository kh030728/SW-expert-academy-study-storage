#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        scanf("%d %d", &N, &M);
		vector<int> A(N, 0);
        vector<int> B(M, 0);
        vector<int> check(N, 0);
		int tmp;
		for(int i=0; i<N; i++)
        {
            scanf("%d", &A[i]);
        }
        for(int i=0; i<M; i++)
        {
             scanf("%d", &B[i]);
        }
        sort(B.begin(), B.end());
        
		for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(A[j]<=B[i]){	//j번 위원은 개최 비용이 Bj를 넘지 않는 종목 중에서 가장 재미있는 경기에 표를 준다.
                    check[j]++;
                	break;		//심사위원은 하나의 종목에만 투표가 가능.
                }
            }
        }
            
        int best = 0;
        int idx = 0;
        //가장 많은 표를 얻은 것을 찾는 부분
        for(int i=0; i<N; i++)
        {
            if(check[i] > best)
            {
                best = check[i];
                idx = i;
            }
        }
        printf("#%d %d\n", test_case, idx+1);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}