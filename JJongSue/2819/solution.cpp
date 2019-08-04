#include <iostream>
#include <vector>
using namespace std;

void search(int y, int x, int N, int level);
void is_there(int N);
static vector<int> num;
static int pan[4][4];
int main(void)
{
    int testcase_num;
    cin >> testcase_num;
    for (int t = 0; t < testcase_num; t++)
    {
        num.clear();
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> pan[i][j];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                search(i, j, 0, 1);
        cout << "#" << t+1 << " " << num.size() << endl;
    }

    return 0;
}
void search(int y, int x, int N, int level)
{
    if (x > 3 || x < 0 || y > 3 || y < 0)
        return;
    if (level == 7)
        is_there(N * 10 + pan[y][x]);
    else
    {
        search(y, x - 1, N * 10 + pan[y][x], level + 1);
        search(y, x + 1, N * 10 + pan[y][x], level + 1);
        search(y - 1, x, N * 10 + pan[y][x], level + 1);
        search(y + 1, x, N * 10 + pan[y][x], level + 1);
    }
}
void is_there(int N)
{
    for (int i = 0; i < num.size(); i++)
        if (num[i] == N)
            return;

    num.push_back(N);
}
