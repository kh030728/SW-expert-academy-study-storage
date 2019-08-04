#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dfs(int y, int x, int level, vector<vector<bool>> &is_visted, vector<bool> &l);
int max(int a, int b, int c, int d);
int max(int a, int b, int c, int d, int f);

static int R, C;
static vector<vector<char>> island;
static vector<vector<bool>> visted;
static vector<bool> al(26, false);
int main(void)
{
    int testcase_num = 0;
    cin >> testcase_num;
    for (int testcase_i = 0; testcase_i < testcase_num; testcase_i++)
    {
        R = 0, C = 0;
        cin >> R >> C;
        island.clear();
        island.assign(R, vector<char>(C, 'a'));
        visted.clear();
        visted.assign(R, vector<bool>(C, false));
        for (int i = 0; i < R; i++)
        {
            char s1[20];
            string a;
            //scanf("%s", s1);
            cin >> a;
            for (int j = 0; j < C; j++)
                //island[i][j] = s1[j];
                island[i][j] = a.at(j);
        }
        //printf("#%d %d", testcase_i+1, dfs(0, 0, 0, visted, al));
        cout << "#" << testcase_i + 1 << " " << dfs(0, 0, 0, visted, al) << endl;
    }
    return 0;
}
int dfs(int y, int x, int level, vector<vector<bool>> &is_visted, vector<bool> &l)
{

    // x,y가 범위를 넘어갈 경우, 이미 방문했을 경우 0반환,
    if (x > C - 1 || x < 0 || y > R - 1 || y < 0)
        return 0;
    if (is_visted[y][x])
        return 0;
    if (l[island[y][x] - 'A'])
        return 0;
    if (level == 25)
        return 26;

    vector<bool> l2 = l;
    vector<vector<bool>> is_visted2 = is_visted;
    is_visted2[y][x] = true;
    l2[island[y][x] - 'A'] = true;

    int a=0,b=0,c=0,d=0;
    a = dfs(y, x - 1, level + 1, is_visted2, l2);
    if( a != 26)
    {
        b = dfs(y, x + 1, level + 1, is_visted2, l2);
        if( b != 26 )
        {
            c = dfs(y - 1, x, level + 1, is_visted2, l2);
            if ( c != 26)
            {
                d = dfs(y + 1, x, level + 1, is_visted2, l2);
            }
        }
    }
    return max(level+1, a, b, c, d);

    /*return max(level + 1, dfs(y, x - 1, level + 1, is_visted2, l2),
               dfs(y, x + 1, level + 1, is_visted2, l2), dfs(y - 1, x, level + 1, is_visted2, l2), dfs(y + 1, x, level + 1, is_visted2, l2));*/
}

int max(int a, int b, int c, int d)
{
    int max1 = max(a, b);
    int max2 = max(c, d);
    return max(max1, max2);
}
int max(int a, int b, int c, int d, int f)
{
    int maxa = max(a, b, c, d);
    return max(maxa, f);
}
