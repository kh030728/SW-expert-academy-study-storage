#include <iostream>
#include <cstring>
using namespace std;
//Prim algorithm

int main(void)
{
    int test_case;
    cin >> test_case;
    for(int T = 1; T <= test_case ; T++)
    {
        int V; int E;
        cin >> V >> E;
        int graph[V][V];
        int vertex[V];
        int answer = 0;
        //그래프 초기화
        memset(graph, 0, sizeof(graph));
        memset(vertex, 0, sizeof(vertex));
        for(int e = 0; e < E ; e++)
        {
            int A; int B; int C;
            cin >> A >> B >> C;
            graph[A-1][B-1] = C;
            graph[B-1][A-1] = C;
        }
        int index = 0;
        while(true)
        {
            if(vertex[index] == 1)
                continue;
            int esc = 0;
            for(int k = 0; k < V; k++)
            {
                esc += vertex[k];
            }
            if(esc == V) break;
            
            int min= 1000001;
            int mindex = 0;
            for(int col = 0 ; col < V; col++)
            {
                if(min > graph[index][col] && graph[index][col] != 0 && vertex[col] == 0)
                {
                    mindex = col;
                    min = graph[index][col];
                }
            }
            answer += min;
            vertex[mindex] = 1;
            index = mindex;
        }
        cout << answer;
        
    }
}