//5051
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void score(int sum, int level);
void is_there(int N);
static vector<int> num;
static vector<int> answer;
static vector<bool> ans;
int main(void)
{
    int testcase_num;
    cin >> testcase_num;
    for (int t = 0; t < testcase_num; t++)
    {
        int N;
        cin >> N;
        num.clear();
        num.assign(N, 0);
        ans.clear();
        ans.assign(10001, false);
        for (int i = 0; i < N; i++)
            cin >> num.at(i);
        score(0, 0);
        int a=0;
        for(int i=0;i<10001;i++)
            if(ans[i]) a++;
        cout << "#" << t + 1 << " " << a << endl;
    }

    return 0;
}
void score(int sum, int level)
{
    if (level == num.size())
        ans[sum] =true; //is_there(sum);
    else
    {
        score(sum, level + 1);
        score(sum + num[level], level + 1);
    }
}
/*
void is_there(int N)
{
    
    for (int i = 0; i < answer.size(); i++)
        if (answer[i] == N)
            return;

    vector<int>::iterator iter;
    iter = find(answer.begin(), answer.end(), N);
    if (iter == answer.end())
        answer.push_back(N);
}
*/