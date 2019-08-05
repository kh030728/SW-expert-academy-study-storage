#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int test = 0;
    scanf("%d", &test);
    for (int test_i = 1; test_i <= test; test_i++)
    {
        int N = 0;
        scanf("%d", &N);
        //printf("%d")
        vector<int> a(N, 0);
        stack<int> s;
        vector<int> b(N, 0);
        bool is_end = false;
        int j = 1;
        string ans = "";
        for (int i = 0; i < N; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            if (is_end == false)
            {
                while (1)
                {
                    if (tmp == j)
                    {
                        ans += "+-"; 
                        j++;
                        break;
                    }
                    else if (tmp > j){
                        s.push(j);
                        ans+="+";
                        j++;
                    }
                    else{
                        if(s.empty()){
                            is_end=true;
                            break;
                        }
                        else{
                            if(tmp == s.top())
                            {
                                ans+="-";
                                s.pop();
                                break;
                            }
                            else
                            {
                                is_end=true;
                                break;
                            }
                            
                        }
                    }
                }
            }

            //scanf("%d", &a[i]);

            //b[i] = i + 1;
        }
        if(is_end) ans = "NO";
        cout << "#" << test_i << " " << ans << endl;
    }
    return 0;
}