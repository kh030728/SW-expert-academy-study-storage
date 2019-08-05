#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    for(int testcase_i=1;testcase_i<=10;testcase_i++)
    {
        int dump =0;
        scanf("%d", &dump);
        int box[100] = {0, };
        for(int i=0;i<100;i++)
        {
            int tmp;
            scanf("%d", box+i);
        }
        sort(box,box+100);
        int min_i=0, max_i=0;
        for(int i=0;i<dump;i++)
        {
            min_i=99;;
            max_i=0;
            for(int j=0;j<99;j++)
            {
                if(box[j] < box[j+1])
                {
                    min_i=j;
                    break;
                }
            }
            for(int j=99;j>0;j--)
            {
                if(box[j] > box[j-1])
                {
                    max_i=j;
                    break;
                }
            }
            if(min_i >= max_i)
                break;
            else
            {
                box[min_i]++;
                box[max_i]--;
            }            
        }
        printf("#%d %d\n", testcase_i, *max_element(box,box+100)-*min_element(box,box+100));
    }
    return 0;
}