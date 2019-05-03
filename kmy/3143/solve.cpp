#include<iostream>
#include <string>
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
        string A, B;
        cin>>A>>B;
         
        int cnt = 0;
        for(int i=0; i<A.size(); i++)
        {
            if(B[0] == A[i])
            {
                int k = i + 1;
                bool flag = true;
                for(int j=1; j<B.size(); j++, k++)
                {
                    if(B[j] != A[k]){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    i = k-1;
                else
                {
                    i = i;
                }
            }
            cnt++;
        }
        cout<<"#"<<test_case<<" "<<cnt<<'\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}