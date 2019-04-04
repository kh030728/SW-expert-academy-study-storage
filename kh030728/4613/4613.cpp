#include<iostream>
#include <vector>

using namespace std;
int countColor(vector <vector<char>> array, int weight, int height, int Wh, int Bh) {
    int count =0;
	for(int i = 0 ; i < Wh; i++) {
            for(int j = 0 ; j < weight; j++) {
                if(array[i][j] != 'W')
                    count++;
            }
        }
    for(int i = Wh ; i < Bh+Wh; i++) {
        for(int j = 0 ; j < weight; j++) {
            if(array[i][j] != 'B')
                count++;
        }
    }
    for(int i = Bh+Wh ; i < height; i++) {
        for(int j = 0 ; j < weight; j++) {
            if(array[i][j] != 'R')
                count++;
        }
    }
    
    return count;
}
int minColor(vector<vector<char>> array, int weight, int height, int Rh) {
    int min = 99999999;
   	int Wh = 1;
    int Bh= height - Rh - Wh; 
    for( ; Bh >= 1 ; Bh--,Wh++){
        int tmp = countColor(array,weight,height,Wh,Bh);
        if(tmp < min)
           min = tmp;
    }
 	
    if(height-2 == Rh) {
        return min;
    }
    else {
    	int tmp = minColor(array,weight,height,Rh+1);
        if(tmp < min) return tmp; else return min;
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
        
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 배열 생성
        int height;
		int weight;
        cin>>height >> weight;
    	vector<vector<char>> array;
    	array.assign(height, vector<char>(weight,0));
        // 배열에 값 넣기
    	for(int i = 0 ; i < height ; i++) 
            for(int j = 0 ; j < weight ; j++) 
                cin>>array[i][j];
        int h = height/2; //h는 각 줄의 높이
        cout <<"#"<<test_case<<" "<< minColor(array,weight,height,1) << endl;
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}