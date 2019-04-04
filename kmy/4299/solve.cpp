#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int D, H, M;
        cin>>D>>H>>M;
        int X = D-11;
        int Y = H - 11;
        int Z = M - 11;
        
        int Time = X*24*60+Y*60 + Z;
        if(Time<0){
            cout<<"#"<<test_case<<" "<<"-1"<<endl;
        	continue;
        }
        cout<<"#"<<test_case<<" "<<Time<<endl;
        
        
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}