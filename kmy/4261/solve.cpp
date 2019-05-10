#include<iostream>
#include <string>
#include <vector>
using namespace std;
string change(string x)
{
    string y = "";
    for(int i=0; i<x.size(); i++)
    {
        if(x[i] == 'a' || x[i] == 'b' || x[i] == 'c')
        {
            y+='2';
        }
        else if(x[i] == 'd' || x[i] == 'e' || x[i] == 'f')
        {
            y+='3';
        }
        else if(x[i] == 'g' || x[i] == 'h' || x[i] == 'i')
        {
            y+='4';
        }
        else if(x[i] == 'j' || x[i] == 'k' || x[i] == 'l')
        {
            y+='5';
        }
        else if(x[i] == 'm' || x[i] == 'n' || x[i] == 'o')
        {
            y+='6';
        }
        else if(x[i] == 'p' || x[i] == 'q' || x[i] == 'r' || x[i] == 's')
        {
            y+='7';
        }
        else if(x[i] == 't' || x[i] == 'u' || x[i] == 'v')
        {
            y+='8';
        }
        else if(x[i] == 'w' || x[i] == 'x' || x[i] == 'y' || x[i] == 'z')
        {
            y+='9';
        }
    }
    return y;
}
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
        int N;
        vector<string> check;
        string tmp;
        cin>>X>>N;
        for(int i=0; i<N; i++)
        {
            cin>>tmp;
            tmp = change(tmp);
            check.push_back(tmp);
        }
        int cnt = 0;
        for(int i=0; i<N; i++)
        {
            if(check[i].find(X) != string::npos)
            {
                cnt++;
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<'\n';
 
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}