#include <iostream>
#include <stack>
using namespace std;
	
int main(void)
{
    for(int test_case = 1; test_case <= 10 ; test_case++)
    {
        stack<char> s;
        char tmp; int word_length=0;
        cin >> word_length;
        string answer ="";
        for(int i = 0 ; i < word_length ; i ++)
        {
        	cin >> tmp;
        	if(s.empty()) s.push(tmp); // 비어있는 경우 push
        	else if(s.top() == tmp) s.pop(); // 탑이 넣으려는 값과 같은 경우 pop
        	else s.push(tmp); // 두 경우가 아닌 경우 push
        }
        while(!s.empty())
        {
            answer = s.top() +answer;
            s.pop();
        }
        cout <<"#" <<test_case << " " <<answer << endl;
    }
 	return 0;   
}