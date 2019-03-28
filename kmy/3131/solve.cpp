#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool chae[1000001];
    
    // chae�� �ε����� ����, ���� ���� 0�̸� �Ҽ��� ���ɼ��� �ִ� ��, -1 �̸� �Ҽ��� �ƴ�, 1�̸� �Ҽ�
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