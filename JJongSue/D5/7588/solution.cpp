#include <iostream>
#include <vector>
#include <utility>
#include <memory.h>
using namespace std;
static vector<vector<int>> line;
static vector<int> stack;
static int N, i;
void find_line(int a);
void removeStack(int a);
int main(void)
{
    register int testcase_num = 0;
    cin >> testcase_num;
    for (register int testcase_i = 0; testcase_i < testcase_num; testcase_i++)
    {
        cout << "#" << testcase_i + 1 << endl;
        N = 0;
        cin >> N;
        line.assign(N, vector<int>(2, 0));
        for (i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            int tmp1, tmp2;
            switch (a)
            {
            case 1:
                cin >> tmp1 >> tmp2;
                //line.push_back({1, tmp1, tmp2});
                //line[i][0]=1;
                line[i][0] = tmp1;
                line[i][1] = tmp2;
                stack.push_back(tmp1);
                stack.push_back(tmp2);

                break;
            case 2:
                cin >> tmp1;
                removeStack(tmp1);
                //line.push_back({2});

                break;
            default:
                cin >> tmp1;
                find_line(tmp1);
                //line.push_back({3});
                break;
            }
        }
        line.clear();
        stack.clear();
    }

    return 0;
}
void find_line(int a)
{
    if (i == 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (stack.empty())
    {
        cout << "NO" << endl;
        return;
    }

    register long long max;
    register long long t;
    /*
    for(int j=0;j<N;j++)
    {
        if(line[j][0] == 1)
        {
            t= (line[j][1]*a)+line[j][2];
            if(t>max) max=t;
        }
    }
    if(max ==(-2)*(1,000,000,000,000,000,000) ) cout << "NO" << endl;
    else cout << max << endl;*/

    max = stack[0] * a + stack[1];
    for (int j = 2; j < stack.size(); j += 2)
    {

        t = stack[j] * a + stack[j + 1];
        if (t > max)
            max = t;
    }
    //if(max ==(-2)*(1,000,000,000,000,000,000) ) cout << "NO" << endl;
    cout << max << endl;
}
void removeStack(int a)
{
    register int x=line[a-1][0],y=line[a-1][1];
    for (int k = 0; k < stack.size(); k += 2)
    {
        if (stack.at(k) == x)
        {
            if (stack.at(k + 1) == y)
            {
                stack.erase(stack.begin() + k + 1);
                stack.erase(stack.begin() + k);
                return;
            }
        }
    }
}