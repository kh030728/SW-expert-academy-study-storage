#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(void)
{

    for(int i=0;i<10;i++)
    {
        int testcase_num=0, left_one=0, left_two=0, right_one, right_two, center=0, sun=0;
        cin >> testcase_num;
        cin >> right_one;
        cin >> right_two;
        for(int j=2;j<testcase_num;j++)
        {
            left_one = left_two;
            left_two = center;
            center=right_one;
            cin >> right_two;
            int max=four_max(left_one, left_two, right_one, right_two);
            if( center > max ) sun += center - max;
        }
    }
    return 0;
}
int four_max(int a, int b, int c ,int d)
{
    if(max(a,b) >= max(c,d) ) return max(a,b);
    else return max(c,d);
}