#include <iostream>
using namespace std;
int main(void)
{
    int testcase_num;
    cin >> testcase_num;
    for(int i=0;i<testcase_num;i++)
    {
        int sum=0, num;
        for(int j=0;j<10;j++)
        {
            cin >> num;
            sum+=num;
        }
        cout << "#" << i+1 << " ";
        if(sum%10 > 4) cout << sum/10+1 << endl;
        else cout << sum/10 << endl;
    }
    return 0;
}