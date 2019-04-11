#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int TestNum;
	int tmp = 0;
	int ary[9][9] = { 0 };
	vector <int> Z;

	cin >> TestNum;

	Z.resize(TestNum,1);

	for (int k = 0; k < TestNum; k++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> ary[i][j];
				tmp += ary[i][j];
			}
			if (tmp != 45) Z[k] = 0;
			tmp = 0;
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				tmp += ary[j][i];
			}
			if (tmp != 45) Z[k] = 0;
			tmp = 0;
		}
		for (int i = 0; i < 9; i+=3)
		{
			for (int j = 0; j <3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					tmp += ary[i+j][i+k];
				}
			}
			if (tmp != 45) Z[k] = 0;
			tmp = 0;
		}
		
	}

	for (int i = 0; i < TestNum; i++)
	{
		cout << "#" << i + 1 << " " << Z[i] << endl;
	}
}