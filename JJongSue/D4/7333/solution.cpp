#include <iostream>
#include <algorithm>
#include <vector>
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
        vector<int> box;
        deque<int> box2;
        int tmp;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            if (tmp >= 50)
                answer++;
            else{
                box.push_back(tmp); box2.push_back(tmp);}
        }
        if (!box.empty())
        {
            sort(box.begin(), box.end());
            int sum=box2.back();
            while(!box.empty())
            {

            }
            int idx = box.size()-1;
            int t = box[idx];
            int sum = t;
            for (int j = 0; j < idx; j++)
            {
                sum += t;
                if (sum >= 50)
                {
                    t = box[--idx];
                    sum = t;
                    answer++;
                }
            }
        }

        cout << "#" << i + 1 << " " << answer << endl;
    }
    return 0;
}