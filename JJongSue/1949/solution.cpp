#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// bool dfs(int y, int x, int height, bool use_dig, int level);
int dfs(int y, int x, int height, int level, bool use_dig, vector<vector<bool>> &visted_mount1);
int max(int a, int b, int c, int d);
int max(int a, int b, int c, int d, int f);

static vector<vector<int>> mount;
static vector<vector<bool>> visted_mount;
static vector<int> load;
static int k, N;
int main(void)
{
    int testcase_num;
    cin >> testcase_num;
    for (int i = 0; i < testcase_num; i++)
    {
        int height_max = 0;
        cin >> N;
        cin >> k;
        load.clear();
        mount.clear();
        mount.assign(N, vector<int>(N, 0));
        // mount을 입력하고 max값 탐색
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> mount[j][k];
                if (height_max < mount[j][k])
                    height_max = mount[j][k];
            }
        }
        //max값 발견 시 dfs수행
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (mount[j][k] == height_max)
                {
                    visted_mount.clear();
                    visted_mount.assign(N, vector<bool>(N, false));
                    visted_mount[j][k] = true;
                    load.push_back(max(1, dfs(j, k - 1, height_max, 1, false, visted_mount),
                                       dfs(j, k + 1, height_max, 1, false, visted_mount), dfs(j - 1, k, height_max, 1, false, visted_mount), dfs(j + 1, k, height_max, 1, false, visted_mount)));
                }
            }
        }
        cout << "#" << i + 1 << " " << *max_element(load.begin(), load.end()) << endl;
    }
    return 0;
}
int dfs(int y, int x, int height, int level, bool use_dig, vector<vector<bool>> &visted_mount1)
{

    if (x > N - 1 || x < 0 || y > N - 1 || y < 0)
        return 0;
    if (visted_mount1[y][x])
        return 0;

    vector<vector<bool>> visted_mount2 = visted_mount1;
    visted_mount2[y][x] = true;
    // 현재 높이가 이전 높이보다 낮을 시 dfs수행 level상승 그 중 최대값만 리턴
    if (mount[y][x] < height)
    {
        return max(level + 1, dfs(y, x - 1, mount[y][x], level + 1, use_dig, visted_mount2),
                   dfs(y, x + 1, mount[y][x], level + 1, use_dig, visted_mount2), dfs(y - 1, x, mount[y][x], level + 1, use_dig, visted_mount2), dfs(y + 1, x, mount[y][x], level + 1, use_dig, visted_mount2));
    }
    
    //땅 파는 것을 사용 안했고, 땅을 팠을 시 이전 높이보다 작으면 dfs수행
    if (use_dig == false && (mount[y][x] - k < height))
    {
        return max(level + 1, dfs(y, x - 1, height - 1, level + 1, true, visted_mount2),
                   dfs(y, x + 1, height - 1, level + 1, true, visted_mount2), dfs(y - 1, x, height - 1, level + 1, true, visted_mount2), dfs(y + 1, x, height - 1, level + 1, true, visted_mount2));
    }
    else
        return 0;

    return 0;
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
