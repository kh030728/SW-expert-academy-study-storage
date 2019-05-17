#include <iostream>
#include <algorithm>
using namespace std;

int results = 999999999;
int search(int *height, int N, int idx, int sum, int target)
{
    if(idx == (N))
    {
        if(sum>=target){
        results = min(sum, results);
        }
        return 1;
    }
    else{
        search(height, N, idx+1, sum+height[idx], target);
        search(height, N, idx+1, sum, target);
    }
    return 0;
}
int main()
{
    int T;
    cin>>T;
    for(int test_case = 0; test_case<T; test_case++)
    {
        results = 2147483647;
        int height[20];
        int N, target;
        cin>>N>>target;
        for(int i=0; i<N; i++)
        {
            int x;
            cin >> x;
            height[i] = x;
        }
        search(height, N, 0, 0, target);
        cout<<"#"<<test_case+1<<" "<<results - target<<endl;
    }
    return 0;
}