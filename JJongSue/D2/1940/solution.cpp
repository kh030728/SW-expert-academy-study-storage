#include <iostream>
using namespace std;
int main(void)
{
    int testcase_num = 0;
    cin >> testcase_num;
    for (int testcase_i = 0; testcase_i < testcase_num; testcase_i++)
    {
        int answer=0;
        int N;
        int v = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a;
            switch (a)
            {
            case 1:
            cin >> b;
                v += b;
                answer += v;
                /* code */
                break;
            case 2:
            cin >> b;
                v -= b;
                if (v < 0)
                    v = 0;
                answer += v;
                break;
            default:
                answer += v;
                break;
            }
        }
        cout << "#" << testcase_i+1 << " " << answer << endl;
    }

    return 0;
}