#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    for(int test_case=1; test_case<=10; test_case++)
    {
        int dump;
        cin>>dump;
        priority_queue< int, vector<int>, less<int> > pq;
        priority_queue< int, vector<int>, greater<int> > pq2;
        for(int i=0; i<100; i++)
        {
            int x;
            cin>>x;
            pq.push(x);
            pq2.push(x);
        }
        for(int i=0; i<dump; i++)
        {
            int tmp = pq.top();
            pq.pop();
            pq.push(tmp-1);
            int tmp2 = pq2.top();
            pq2.pop();
            pq2.push(tmp2+1);
            if( pq.top() == pq2.top())
            {
                break;
            }
        }
        cout<<"#"<<test_case<<" "<<pq.top()-pq2.top()<<endl;
    }
    return 0;
}