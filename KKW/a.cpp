#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	/*int* a;*/
	int a_length = 0, temp = 0, left = 0, right = 0, result = 0, case_num=1, length=0;

	int tmp[5] = {0};
	int res[10] = { 0 };
	vector <int> a;

	for (case_num; case_num <=10; case_num++)
	{
		cout << case_num << "번째 case // 갯수 입력 : ";
		cin >> length ;

		a.resize(length);

		cout << "건물 숫자 입력";

		for (int i = 0; i < a.size(); i++)
		{
			cin >> a[i];
		}

		for (int i = 2; i < a.size() - 2; i++)
		{
			tmp[0] = a[i - 2];
			tmp[1] = a[i - 1];
			tmp[2] = a[i];
			tmp[3] = a[i + 1];
			tmp[4] = a[i + 2];

			if (tmp[0] > tmp[1]) left = tmp[0];
			else left = tmp[1];
			if (tmp[3] > tmp[4]) right = tmp[3];
			else right = tmp[4];

			if (left < a[i] && right < a[i])
			{
				if (left > right) result += a[i] - left;
				else result += a[i] - right;
			}
		}
		res[case_num-1] = result;
		result = 0;
	}
	for (int i = 0; i < 10; i++)
	{
		cout <<endl << "#" << i + 1<<" " << res[i] << endl;
	}
	return 0;
}