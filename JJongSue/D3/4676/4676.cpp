#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
    int test=0;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        string s;
        cin >> s;
        int H, tmp;
        scanf("%d", &H);
        vector<int> pq;
        for(int i=0;i<H;i++)
        {
            scanf("%d", &tmp);
            pq.push_back(tmp);
        }
        string answer;
        sort(pq.begin(), pq.end());
        int iter = 0, i;
        /*for(i=0;i<pq.size();i++)
        {
            if(pq[i]!=0){
                answer+='-';
            }
            else {
                iter=i;
                break;
            }
        }*/
        for(i=0;i<s.size();i++)
        {
            for(int j=iter;j<pq.size();j++)
            {
                if(pq[j] == i)
                {
                    answer+='-';
                }
                else{
                    iter=j;
                    break;
                }
            }           
            answer+=s[i];
        }
        for(int i=0;i<pq.size();i++)
        {
            if(pq[i] == s.size()) answer+='-';
        }
        cout << "#" << test_i << " " << answer << endl;
    }
}