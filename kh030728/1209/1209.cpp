#include <iostream>
#define MAX_SIZE 100

using namespace std;

int main(void)
{
    int T =0;
    //행합
    for(int test_case = 1 ; test_case <= 10 ; test_case++)
    {
        cin >> T;
		int array[MAX_SIZE][MAX_SIZE]={ {0,}, };
    	int max_sum = 0;
        //배열 받기
        for(int i = 0 ; i < MAX_SIZE ; i ++)
    	{
     		for(int j = 0; j < MAX_SIZE ; j++)
        	{
                cin >> array[i][j];
        	}
    	}
        //행합비교
        for(int i = 0 ; i < MAX_SIZE ; i ++)
    	{
        	int sum =0;
     		for(int j = 0; j < MAX_SIZE ; j++)
        	{
            	sum +=array[i][j];
        	}
        	if(max_sum < sum)
            	max_sum = sum;
    	}
        //열합비교
        for(int i = 0 ; i < MAX_SIZE ; i ++)
    	{
        	int sum =0;
     		for(int j = 0; j < MAX_SIZE ; j++)
        	{
            	sum +=array[j][i];
        	}
        	if(max_sum < sum)
            	max_sum = sum;
    	}
        //대각 비교
        int tmp = 0;
        for(int i = 0 ; i < MAX_SIZE ; i++)
        {
            tmp += array[i][i];
        }
        if(max_sum < tmp)
            max_sum =tmp;
        
        tmp =0;
        for(int i = 0 ; i < MAX_SIZE ; i++)
        {
            tmp += array[ 99-i ][i];
        }
        if(max_sum < tmp)
            max_sum =tmp;
        
        cout <<"#" <<test_case <<" "<< max_sum << endl;
    }
    
 	return 0;   
}