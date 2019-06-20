#include <iostream>
using namespace std;
int main(void)
{
    int x;
    int y;
    int T;
    cin >> T;
    for(int test_case = 0; test_case < T ; test_case++)
    {
        int answer = 0;
        cin >> x >> y;
        if(x != y && x-2 != y)
        {
            cout << "No Number" << endl;
            continue;
        }
        if(x == y)
        {
            if(x != 0)
            {
                for(int i = 1 ; i <= x ; i++)
                {
                    if(i%2 == 1)
                        answer++;
                    else
                        answer +=3;
                }
            }
        }
        else
        {
            for(int i = 1 ; i <= x ; i++)
            {
                if(i%2 == 1)
                    answer++;
                else
                    answer +=3;
            }
            answer -=2;
        }
        cout << answer << endl;
    }
    return 0;
}