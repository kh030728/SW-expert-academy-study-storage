#include <iostream>
#include <stdio.h>
using namespace std;
int maze[16][16] = {{0,},};
char T=1;
void initMaze() {
	for(int i = 0 ; i < 16 ; i++) {
     	for(int j = 0; j < 16 ; j++) {
            char t;
            cin >> t;
            if(t =='0') maze[i][j]=0;else if(t == '1') maze[i][j]=1; else if(t=='2') maze[i][j]=2; else if(t=='3') maze[i][j]=3;
        }
    }
}
int dfs(int startX =1,int startY=1) {
    int x = startX;
    int y = startY;
    int result = 0;
    //답에 도달한 경우 탈출
    if(maze[x-1][y] == 3 || maze[x+1][y] == 3 || maze[x][y-1] == 3 || maze[x][y+1] == 3) return 1;
    //길을 찾읍시다.
    maze[x][y] = 1; //현재 위치를 1으로 바꾼다.(길을 거꾸로 되돌아가는 경우를 막는 것이다.)
    if(maze[x-1][y] == 0) {if(dfs(x-1,y) == 1) return 1;}
    if(maze[x+1][y] == 0) {if(dfs(x+1, y) == 1) return 1;}
    if(maze[x][y-1] == 0) {if(dfs(x,y-1) == 1) return 1;}
    if(maze[x][y+1] ==0) {if(dfs(x,y+1) == 1) return 1;}
    
    //길을 찾지 못한 경우
    return 0;
}
int main(void)
{
    for(int i = 0 ; i <10;i++) {
    	scanf("%d",&T);
    	printf("#%d ",T);
    	initMaze();
    	printf("%d\n",dfs(1,1));
    }
    return 0;
}