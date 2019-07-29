#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int testcase_num = 0;
    scanf("%d", &testcase_num);
    for(int testcase_i=1;testcase_i<=testcase_num;testcase_i++)
    {
        int N=0, B=0;
        scanf("%d %d", &N, &B);
        int tmp = 0;
        vector<int> key;
        for(int i=0;i<N;i++)
        {
            scanf("%d", &tmp);
            key.push_back(tmp);
        }
        sort(key.begin(), key.end());
        if(key[key.size()-1] == B) printf("#%d 0\n", testcase_i);
        else{
            int min = B;
            for(int i=0;i< (1<<key.size());i++ )
            {
                int tmpAns = 0;
                for(int j=0;j<key.size();j++)
                {
                    if( (i>>j) & 1)
                        tmpAns+=key[j];
                }
                if(min > tmpAns-B && tmpAns-B>=0)
                    min=tmpAns-B;
            }
            printf("#%d %d\n", testcase_i, min);
        }
    }
    return 0;
}