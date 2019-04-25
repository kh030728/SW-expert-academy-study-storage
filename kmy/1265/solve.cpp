#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int test_case = 1; test_case<=T; test_case++)
    {
        int X[101] = {0,};
        int dal, p;
        cin>>dal>>p;
        int average = dal/p;
        for(int i=0; i<p; i++)
        {
            X[i] = average;
        }
        for(int i=0; i<(dal-average*p); i++)
        {
            X[i]++;
        }
        long long sum = 1;
        for(int i=0; i<p; i++)
        {
            sum *= X[i];
        }
        cout<<"#"<<test_case<<" "<<sum<<endl;
    }
    return 0;
}