#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(void)
{
    int testcase_num = 0;
    cin >> testcase_num;
    for (int i = 0; i < testcase_num; i++)
    {
        int N = 0;
        int answer = 0;
        cin >> N;
        deque<int> box;
        int tmp;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            if (tmp >= 50)
                answer++;
            else
                box.push_back(tmp);
        }
        sort(box.begin(), box.end());
        while (!box.empty())
        {
            /*
            if (box.back() >= 50)
            {
                box.pop_back();
                answer++;
            }*/

            int weight = 50 / box.back();
            if (50 % box.back() == 0)
                weight -= -1;
            //cout << box.back();
            box.pop_back();
            //cout << "box pop back()" << endl;
            for (int k = 0; k < weight; k++)
            {
                if (!box.empty())
                {
                    //cout << box.front();
                    box.pop_front();
                    //cout << "box pop front" << endl;
                }
            }
            answer++;
        }
        cout << "#" << i + 1 << " " << answer << endl;
    }
    return 0;
}