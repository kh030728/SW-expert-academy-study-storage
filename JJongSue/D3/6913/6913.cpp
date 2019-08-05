#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int testcase_num=0;
    scanf("%d", &testcase_num);
    for(int testcase_i=1;testcase_i<=testcase_num;testcase_i++)
    {
        int N=0, M=0;
        scanf("%d %d", &N, &M);
        int max_ans = 0, ans_num =0;
        int tmp=0;
        for(int i=0;i<N;i++)
        {
            int tmp_sum=0;
            for(int j=0;j<M;j++)
            {
                scanf("%d", &tmp);
                tmp_sum+=tmp;
            }
            if(tmp_sum > max_ans){
                max_ans=tmp_sum;
                ans_num=1;
            }
            else if(tmp_sum == max_ans)
            {
                ans_num++;
            }
        }
        printf("#%d %d %d\n", testcase_i, ans_num, max_ans);
    }

    return 0;
}