#include <iostream>
#include <vector>

using namespace std;

int main(){
	for(int test_case = 1; test_case<=10; test_case++)
    {
        int test, M;
        cin>>test>>M;
        bool edge[100][100] = {false,};

        for(int i=0; i<M; i++)
        {
            int a, b;
            cin>>a>>b;
            edge[a][b] = true;

        }
        
        vector<int> que;
        que.push_back(0);
        bool flag = false;
        while(que.size() != 0)
        {
            int x=*que.begin();
            que.erase(que.begin());
            for(int j = 0; j<100; j++)
            {
                if(edge[x][j])	//연결되어 있다면
                {
                   	if(j == 99)	//도착지점이라면
                    {
                        while(!que.empty())	//도착지점이라면 다 지워버리고
                            que.erase(que.begin());
                        flag = true;
                        break;		//포문 종료
                    }
                    else{	//도착지점이아니라면 계속 진행해야하기때문에 큐에 넣어줌
                    	que.push_back(j);
                    }
                }
            }
        }
        if(flag)
            cout<<"#"<<test_case<<" "<<"1"<<endl;
        else
            cout<<"#"<<test_case<<" "<<"0"<<endl;
        
    }

	return 0;
}