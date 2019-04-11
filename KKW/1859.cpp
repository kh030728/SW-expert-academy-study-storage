#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
	int testcasenum, day, tmp, top,  counter = 0;
	unsigned int prc=0;
	
	stack<int> price;
	double full_pf = 0, sum = 0;

	ifstream file("input.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error"; exit(1);
	}

	
	file >> testcasenum;

	for (int i = 0; i < testcasenum; i++)
	{
		file >> day;
	

		for (int j = 0; j < day; j++)
		{
			file >> tmp;
			price.push(tmp);
		}

		top = price.top();
		price.pop();
		

		while (!price.empty())
		{
				tmp = price.top();
				price.pop();

				if (top > tmp)
				{
					sum += tmp;
					counter++;
				}
				else
				{
					prc = (top*counter) - sum;
					counter = 0;
					full_pf += prc;
					sum = 0;
					prc = 0;
					top = tmp;
				}

		}

		prc = (top*counter) - sum;
		full_pf += prc;
		sum = 0;
		prc = 0;
		counter = 0;
	
		cout << "#" << i + 1 <<  " " << full_pf  << endl;
		full_pf = 0;
	}


	
}