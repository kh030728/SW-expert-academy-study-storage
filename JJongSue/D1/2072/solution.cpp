#include<iostream>
using namespace std;
int main(void)
{
    int N, input_num;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int sum=0;
        for(int j=0;j<10;j++)
        {
            cin >> input_num;
            if ((input_num&1)) sum+=input_num;
        }
        cout << "#" << i+1 << " " << sum << endl;
    }
    return 0;
}