#include <iostream>
using namespace std;

int main()
{
	int case_num, case_num2;
	double per, pay, result = 0;

	cin >> case_num;

	for (int i = 1; i <= case_num; i++)
	{
		cin >> case_num2;
		result = 0;
		for (int j = 0; j < case_num2; j++)
		{
			cin >> per >> pay;
			result += per * pay;
		}
		cout << fixed;
		cout << "#" << i << " " << result << endl;

	}



	return 0;

}