#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

class pos
{
    public:
    int x; int y;
    pos(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};
int map[100][100];
int dist[100][100];
int dx[4] = {-1,1,0,0}; //왼 오 위 아
int dy[4] = {0,0,-1,1};
int bfs(int N)
{
    queue<pos> q;
    q.push(pos(0,0));
    while(!q.empty())
    {
        int cx = q.front().x;
        int cy = q.front().y;
        q.pop();
        for(int i = 0; i < 4 ; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >=N || ny < 0 || ny >=N)
                continue;
            if(dist[cx][cy] + map[nx][ny] < dist[nx][ny])
            {
                dist[nx][ny] = dist[cx][cy] + map[nx][ny];
                q.push(pos(nx,ny));
            }
        }
    }
    return dist[N-1][N-1];
}
int main(void)
{
    int T;
    cin >> T;
    
    for(int test_case = 1 ; test_case <= T; test_case++)
    {
        //변수 초기화 초기화
        int answer = 0;
        int N;
        memset(map, 0, sizeof(map));
        memset(dist, 10000, sizeof(dist));
        dist[0][0] = 0;
        cin >> N;
        // map 받아오기
        for(int r = 0; r < N ; r++)
        {
            for(int c = 0; c < N ; c++)
            {
                char tmp;
                cin >> tmp;
                tmp = tmp - '0';
                map[r][c] = (int)tmp;
            }
        }
        answer =  bfs(N);
        cout << "#" << test_case << " " << answer <<endl;
    }
    
    return 0;
}