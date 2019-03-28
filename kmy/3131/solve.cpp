#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool chae[1000001];
    
    // chae의 인덱스가 숫자, 안의 값이 0이면 소수일 가능성이 있는 수, -1 이면 소수가 아님, 1이면 소수
    for(int i=0; i<1000001; i++)
        chae[i] = true;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (chae[i])
			for (int j = i * 2; j <= 1000000; j += i)
			    chae[j] = false;
	}
    
    for(int i=2; i<=1000000; i++)
    {
        if(chae[i])
            printf("%d ", i);
    }
	return 0;
}