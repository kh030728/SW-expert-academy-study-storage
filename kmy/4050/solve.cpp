#include<iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        priority_queue<int, vector<int>, less<int>> que;
		int N;
        cin>>N;
        for(int i=0; i<N; i++)
        {
            int tmp;
            cin>>tmp;
            que.push(tmp);
        }
        int sum = 0;
        int i=0;
		while(que.size() != 0)
        {
            i++;
            if( i != 3)
            {
            	sum += que.top();
                que.pop();
            }
            else if(i == 3)
            {
                i = 0;
                que.pop();
            }
        }
        cout<<"#"<<test_case<<" "<<sum<<'\n';


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}