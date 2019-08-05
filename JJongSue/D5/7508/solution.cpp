#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int testcase_num;
    cin >> testcase_num;
    for (int i = 0; i < testcase_num; i++)
    {
        vector<int> G;
        int tmp;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> tmp;
            G.push_back(tmp);
        }
        sort(G.begin(), G.end());
        G.push_back(1000001);
        int item_num = 0;
        cin >> item_num;
        vector<int> item(num + 1, 0);
        for (int j = 0; j < item_num; j++)
        {
            cin >> tmp;
            for (int k = 0; k < num + 1; k++)
            {
                if (G.at(k) >= tmp)
                {
                    item[k]++;
                    break;
                }
            }
        }
        if (item[num])
            cout << "#" << i + 1 << " -1" << endl;
        else
        {
            int answer = 0;
            bool is_end = false;
            bool fast_end = true;
            for (int j = 0; j < num; j++)
            {
                if (item[j] > 0)
                    break;
                else if (j == num - 1)
                    is_end = true;
            }
            while (!is_end)
            {
                for (int j = num - 1; j >= 0; j--)
                {
                    fast_end = true;
                    for (int k = j; k >= 0; k--)
                    {
                        if (item[k] > 0)
                        {
                            item[k]--;
                            fast_end = false;
                            break;
                        }
                    }
                    if (fast_end)
                        break;
                }
                answer++;
                for (int j = 0; j < num; j++)
                {
                    if (item[j] > 0)
                        break;
                    else if (j == num - 1)
                        is_end = true;
                }
            }
            cout << "#" << i + 1 << " " << answer << endl;
            G.clear();
            item.clear();
        }
    }
    return 0;
}