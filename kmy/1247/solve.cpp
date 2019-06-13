#include <vector>
#include <iostream>
#include <utility>
using namespace std;
 
vector<pair<int, int>> path;
pair<int, int> office;
pair<int, int> home;
int minimum = 9999999;
//visited는 현재 다녀온 고객,  pos는 현재 위치
bool dfs(int n, int m, int min, int num, vector<bool> visited)    //min 은 현재 까지 이동한 거리, n은 지나온 고객 개수, m은 현재 돌고있는 path 인덱스
{
    int distance;
 
    if (n == num )  //모든 곳을 다 돌았다면
    {
        //cout << n << " " << minimum << '\n';
        distance = min + abs(home.first - path[m].first) + abs(home.second - path[m].second);
        if (distance <minimum)
            minimum = distance;
        return true;
    }
    else
    {
        for (int i = 0; i<num; i++)
        {
            if (!visited[i]) {  //방문하지 않은 곳만 확인
                distance = min + abs(path[i].first - path[m].first) + abs(path[i].second - path[m].second);
                if (distance >minimum)   //현재까지 다녀온 거리가 최소 값보다 크면 중지
                {
                    return false;
                }
                vector<bool> tmp_visited = visited;
                tmp_visited[i] = true;
                dfs(n + 1, i, distance, num, tmp_visited);
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= 10; test_case++)
    {
        minimum = 9999999;
        int N;
        cin >> N;
        path.clear();
        int tmp1, tmp2;
        cin >> office.first >> office.second;
        cin >> home.first >> home.second;
        for (int i = 0; i<N; i++)
        {
            cin >> tmp1 >> tmp2;
            path.push_back(make_pair(tmp1, tmp2));
        }
         
        int distance;
        for (int i = 0; i<N; i++)
        {
            vector<bool> visited(N, false);
            distance = abs(path[i].first - office.first) + abs(path[i].second - office.second);
            visited[i] = true;
            dfs(1, i, distance, N, visited);
        }
        cout << "#" << test_case << " " << minimum << "\n";
    }
    return 0;
}