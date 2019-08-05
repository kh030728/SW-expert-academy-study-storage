#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int test = 0;
    scanf("%d", &test);
    for (int test_i = 1; test_i <= test; test_i++)
    {
        string A, B;
        cin >> A >> B;
        bool is_diff = false;
        if (A.length() != B.length())
        {
            printf("#%d DIFF\n", test_i);
        }
        else
        {
            
            for (int i = 0; i < A.length(); i++)
            {
                if (A[i] == 'B')
                {
                    if (B[i] != 'B')
                    {
                        printf("#%d DIFF\n", test_i);
                        is_diff = true;
                        break;
                    }
                }
                else if (A[i] == 'A' || A[i] == 'D' ||
                         A[i] == 'O' || A[i] == 'P' || A[i] == 'Q' || A[i] == 'R')
                {
                    if (!(B[i] == 'A' || B[i] == 'D' ||
                          B[i] == 'O' || B[i] == 'P' || B[i] == 'Q' || B[i] == 'R'))
                    {
                        printf("#%d DIFF\n", test_i);
                        is_diff = true;
                        break;
                    }
                }
                else{
                    if ((B[i] == 'A' || B[i] == 'D' ||
                          B[i] == 'O' || B[i] == 'P' || B[i] == 'Q' || B[i] == 'R' || B[i]=='B'))
                    {
                        printf("#%d DIFF\n", test_i);
                        is_diff = true;
                        break;
                    }
                }
            }
            if(is_diff == false) printf("#%d SAME\n", test_i);
        }
    }
    return 0;
}