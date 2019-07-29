#include <iostream>
using namespace std;

int main(void)
{
    int testcase_num = 0;
    scanf("%d", &testcase_num);
    {
        for(int testcase_i=1;testcase_i<=testcase_num;testcase_i++)
        {

            int L=0, U=0, X=0;
            scanf("%d %d %d", &L, &U, &X);
            if(L>X) printf("#%d %d\n",testcase_i, L-X);
            else if(X>U) printf("#%d -1\n", testcase_i);
            else printf("#%d 0\n", testcase_i);            
            
        }
    }


    return 0;
}