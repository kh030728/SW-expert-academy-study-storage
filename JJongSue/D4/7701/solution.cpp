#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    register int testcase_num = 0;
    scanf("%d", &testcase_num);
    //cin >> testcase_num;
    for (register int testcase_i = 0; testcase_i < testcase_num; testcase_i++)
    {
        priority_queue<string, vector<string>, greater<string> > pq[50];
        register vector<vector<string>> dic;
        dic.assign(50, vector<string>(0));
        register int N = 0;
        scanf("%d", &N);//cin >> N;
        for (register int i = 0; i < N; i++)
        {
            //register string tmp = "";
            register char tmp[50];
            bool is = true;
            //cin >> tmp;
            scanf("%s", tmp);
            register string s=tmp;            
            for (register int j = 0; j < dic[s.size()-1].size(); j++)
                if (s == dic[s.size()-1][j])
                    {
                        is = false;
                        break;
                    }
            if (is){
                dic[s.size()-1 ].push_back(s);
                
                pq[(s.size()-1)].push(s);
                //pq[s.size()-1].push
            }
                
        }
        //cout << "#" << testcase_i + 1 << endl;
        printf("#%d\n", testcase_i+1);
        for (register int i = 0; i < 50; i++)
        {
            if(dic[i].size() > 0)
            //sort(dic[i].begin(), dic[i].end());
            for (register int j = 0; j < dic[i].size(); j++)
            {
                register int idx=0;                
                printf("%s", pq[i].top().c_str());
                pq[i].pop();/* 
                
                while(idx < dic[i][j].size())
                {
                    printf("%c", dic[i][j].at(idx) );//cout << dic[i][j] << endl;
                    idx++;
                }*/
                printf("\n");   
            }               
        }
        dic.clear();
        

    }
    return 0;
}