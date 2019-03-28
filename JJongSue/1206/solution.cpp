#include <iostream>
#include <algorithm>
using namespace std;
int four_max(int a, int b, int c ,int d);
int main(void)
{
    for(int i=0;i<10;i++)
    {
        int testcase_num=0, left_one=0, left_two=0, right_one=0, right_two=0, center=0, sun=0;
        cin >> testcase_num;
        cin >> left_two;
        cin >> center;
        cin >> right_one;
        cin >> right_two;
        int max=four_max(left_one, left_two, right_one, right_two);
        if( center > max ) sun += center - max;
        for(int j=5;j<=testcase_num;j++)
        {
            left_one = left_two;
            left_two = center;
            center=right_one;
            right_one = right_two;
            cin >> right_two;
            int max=four_max(left_one, left_two, right_one, right_two);
            if( center > max ) sun += center - max;
        }
        cout << "#" << i+1 << " " << sun << endl; 
    }
    return 0;
}
int four_max(int a, int b, int c ,int d)
{
    if(max(a,b) >= max(c,d) ) return (max(a,b));
    else return (max(c,d)) ;
}