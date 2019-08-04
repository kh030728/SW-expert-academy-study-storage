#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static vector<vector<char>> name_map;
static int N, M;
string make_name(int x, int y, string s);
int main(void)
{
    int testcase_num;
    cin >> testcase_num;
    for (int testcase_i = 0; testcase_i < testcase_num; testcase_i++)
    {
        cin >> N >> M;
        name_map.clear();
        name_map.assign(N, vector<char>(M, 0));
        for (int i = 0; i < N * M; i++)
            cin >> name_map[i / M][i % M];
       

        cout << "#" << testcase_i + 1 << " " << make_name(0, 0, "") << endl;
    }
    return 0;
} 
string make_name(int x, int y, string s)
{
    if(y==N-1 && x==M-1) return s+(name_map[y][x]);
    if(y == N-1) return make_name(x+1,y, s+name_map[y][x]);
    if(x == M-1) return make_name(x,y+1, s+name_map[y][x]);
    if(name_map[y+1][x] > name_map[y][x+1]) return make_name(x+1,y, s+name_map[y][x]);
    else if(name_map[y+1][x] < name_map[y][x+1]) return make_name(x,y+1, s+name_map[y][x]);
    else
    {
        string a=make_name(x+1,y, s+name_map[y][x]);
        string b=make_name(x,y+1, s+name_map[y][x]);
        return a.compare(b) > 0 ? b : a;
    }

}
