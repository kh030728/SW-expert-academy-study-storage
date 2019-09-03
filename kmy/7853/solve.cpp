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
		string X;
        cin>>X;
        long answer = 1;
        if(X.size() == 1){
            cout<<"#"<<test_case<<" "<<answer<<'\n';
            continue;
        }
        for(int i=0; i<X.size(); i++)
        {
            if(i == 0)
            {
                if(X[i] == X[i+1])	//맨처음이랑 그 다음 것이 같다면
                    answer *= 1;
                else
                    answer *= 2;
            }
            else if(i == X.size()-1)
            {
                if(X[i] == X[i-1])	//맨마지막이랑 그 전 것이 같다면
                    answer *= 1;
                else
                    answer *= 2;
            }
            else
            {
                bool check1 = (X[i-1] == X[i]);
                bool check2 = (X[i-1] == X[i+1]);
                bool check3 = (X[i] == X[i+1]);
                if(check1 && check2 && check3)	//모든 문자가 같다면
                    answer *= 1;
                else if(!(check1 || check2 || check3))	//전부 다르다면
                    answer *= 3;
                else
                    answer *= 2;
            }
            answer = answer % 1000000007;
        }
		cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}