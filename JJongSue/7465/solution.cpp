#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<bool> &s, vector<vector<bool>> &network, int n);
int main(void)
{
    int testcase_num = 0;
    cin >> testcase_num;
    for (int i = 0; i < testcase_num; i++)
    {
        int N, M;
        cin >> N;
        cin >> M;
        vector<bool> is_visted(N, false);
        vector<vector<bool>> network(N, vector<bool>(N, false));
        int linked_1, linked_2;
        //for(int j=0;j<N;j++) network[j][j]=true;
        for (int j = 0; j < M; j++)
        {
            cin >> linked_1;
            cin >> linked_2;
            network[linked_1 - 1][linked_2-1] = true;
            network[linked_2-1][linked_1 - 1] = true;
        }
        int answer = 0;
        for (int j = 0; j < N; j++)
        {
            if (is_visted[j] == false)
            {
                dfs(is_visted, network, j);
                answer++;
            }
        }
        cout << "#" << i+1 << " " << answer << endl;
    }
    return 0;
}
void dfs(vector<bool> &s, vector<vector<bool>> &network, int n)
{
    for (int i = 0; i < network[n].size(); i++)
    {
        if (s[i] == false && network[n][i])
        {
            s[i] = true;
            dfs(s, network, i);
        }
    }
}