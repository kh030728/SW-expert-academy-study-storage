#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stdio.h>
using namespace std;

short ladder[100][100] = { {0,},};
void initLadder()
{
    for(int i = 0; i < 100 ; i++) 
        for(int j = 0 ; j < 100 ; j++)
            cin >> ladder[j][i];
        
}
bool search(int sp) // sp = start point
{
    int x=sp;
    int h= 0;
    short tmp[100][100] = {{0,},};
    //복사
    memcpy(tmp, ladder, sizeof(ladder));
    while(true)
    {	
        if(tmp[x][h+1] == 2) return true;   //아래칸에 2(정답)이 있을 경우 true 리턴
        else if(h ==99) {return false;}     // 가장 아래칸(99)에 도달하였다면 false 리턴
        // 다음이 도착지점이 아니라면 좌,우 부터 확인
        //아래 조건 식에서 x또는 h가 변할때에 원래 자리에 0을 입력하는 이유는 지나온 길을 지워주기 위해서이다.
        if(x != 99 && x != 0) //좌우측 끝에 있지 않은 경우
            {if(tmp[x+1][h] == 1) {tmp[x][h] = 0; x++;} else if(tmp[x-1][h] ==1) {tmp[x][h] = 0;x--;}}
        else if(x == 0) //좌측 끝에 있는 경우
            { if(tmp[x+1][h] == 1) {tmp[x][h] = 0;x++;} }
        else if(x==99) // 우측 끝에 있는 경우
            {if(ladder[x-1][h] == 1) {tmp[x][h] = 0;x--;}}
        //////////////////////////////////////////////////////////////////////////////////////////
        if(tmp[x][h+1] == 1) { tmp[x][h] = 0; h++; } // 아래로 내려갈 길이 있는 경우.
    }
    return false;
}
int totalSearch()
{
    vector<int> v;
    //시작 지점들을 저장.
    for(int i = 0; i< 100;i++) 
        if(ladder[i][0]==1) 
            v.push_back(i);
    
    //시작 지점을 이용하여 search()를 실행
    for(int i = 0 ; i < v.size() ; i++) 
        if(search(v[i]) == true) return v[i];
    
    return 1000; // 1000 은 실패를 의미
}
int main(void)
{
    int tmp;
    
    for(int T = 1 ; T <= 10 ; T++)
    {
        cin >> tmp;
    	cout << "#"<<tmp;
    	initLadder();
    	cout <<" "<< totalSearch() <<endl;
    }
    return 0;
}