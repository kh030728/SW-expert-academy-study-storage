#include <queue>
#include <iostream>

using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int test_case = 1; test_case<=T; test_case++)
    {
        priority_queue< int, vector<int>, greater<int> > small;
        priority_queue< int, vector<int>, less<int> > big;
        int N, A;
        cin>>N>>A;
        big.push(A);
        long long sum = 0;
        for(int i=0; i<N; i++)
        {
            int a, b;
            cin>>a>>b;
			small.push(a);
            big.push(b);
            if(big.top() > small.top())
            {
                int tmp1 = big.top();
                int tmp2 = small.top();
                big.pop();
                small.pop();
                small.push(tmp1);
                big.push(tmp2);
            }
            sum = (sum + big.top())%20171109;
        }
        cout<<"#"<<test_case<<" "<<sum<<endl;
        
    }
}