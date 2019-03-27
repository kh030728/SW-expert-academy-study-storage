#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int testcase_num;
    cin >> testcase_num;
    for(int i=0;i<testcase_num;i++)
    {
        int N, output=0;
        string X;
        cin >> N >> X;

        for(int j=0;j<X.size();j++)
        {
            output += (X.at(j) - '0') ;
        }
        cout << "#" << i+1 << " " << output%(N-1) << endl;
    }
    return 0;
}