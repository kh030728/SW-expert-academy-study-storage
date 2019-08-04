#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int testcase_num = 0;
    scanf("%d", &testcase_num);
    for(int testcase_i=1;testcase_i<=testcase_num;testcase_i++)
    {
        int N=0, K=0;
        scanf("%d %d", &N, &K);
        vector<bool> homework(N, false);

        for(int i=0;i<K;i++)
        {
            int tmp=0;
            scanf("%d", &tmp);
            homework[tmp-1] = true;
        }
        printf("#%d", testcase_i);
        for(int i=0;i<homework.size();i++)
        {
            if(homework[i] == false)
                printf(" %d", i+1);
        }
        printf("\n");
    }

    return 0;
}