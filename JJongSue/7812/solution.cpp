#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int testcase_num;
    scanf("%d", &testcase_num);
    for(int testcase_iter=0; testcase_iter<testcase_num; ++testcase_iter)
    {
        vector <int> r;
        int N=0, M=0;
        scanf("%d %d", &N, &M);
        for(int i=0;i<N;++i)
        {
            int tmp=0;
            scanf("%d", &tmp);
            r.push_back(tmp);
        }
        int answer=0;
        for(int i=0;i<r.size();++i)
        {
            int tmpM=M;
            for(int j=i;j<r.size();++j)
            {
                tmpM-=r[j];
                if(tmpM==0){
                    answer++;
                    break;
                }
                if(tmpM<0) break;
            }
        }
        printf("#%d %d\n", testcase_iter+1, answer);
    }

    return 0;
}
