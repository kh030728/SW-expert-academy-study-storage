#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(void)
{
    int testcase_num = 0;
    scanf("%d", &testcase_num);
    for(int testcase_i=1;testcase_i<=testcase_num;testcase_i++)
    {
        int P=0;
        scanf("%d", &P);
        vector<int> s(P, 0);
        for(int i=0;i<P;i++)
            scanf("%d", &s[i]);
        if(P==1) printf("#%d %d\n", testcase_i, s[0]*s[0]);
        else
        {
            sort(s.begin(), s.end());
            printf("#%d %d\n", testcase_i, s[0]*s[s.size()-1]);            
        }
        

    }
}