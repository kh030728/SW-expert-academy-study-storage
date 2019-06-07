#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    string t;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        string X;
        int Value = 0;
        bool flag[26];
        getline(std::cin, t);
        for (int i = 0; i<N; i++)
        {
            fill_n(flag, 26, false);
            string tmp;
            int cnt = 0;
            cin.clear();
            getline(std::cin, tmp);
            for (int j = 0; j<tmp.size(); j++)
            {
                if (tmp[j] == ' ' || tmp[j] == 13)  //13이 들어가는 이유 아스키코드 13번이 들어가있음. (비쥬얼은 문제 없는데 여기서만 난리)
                    continue;
                else if (tmp[j] == '\n')
                    break;
            
                if (!flag[tmp[j] - 'A'])    //이전에 나왔던 것이 아니라면
                {
                    int qq = tmp[j];
                    flag[tmp[j] - 'A'] = true;
                    cnt++;
                }
                
            }
            if (cnt>Value)
            {
                Value = cnt;
                X = tmp;
            }
            else if (cnt == Value)
            {
               
                if (tmp < X)
                {
                    X = tmp;
                }
            }
        }
        cout << "#" << test_case << " " << X << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}