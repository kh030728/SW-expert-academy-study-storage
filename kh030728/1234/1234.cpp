#include <iostream>
using namespace std;
string f(string str , int length)
{
    string result = str;
    bool flag = false;
    for(int i = 0; i < length -1 ; i++)
    {
        if(str[i] == str[i+1])
        {
            result.erase(i,2);
            flag = true;
            break;
        }
    }
    if(flag) return f(result, length -2);
    return result;
}
int main(void)
{
    for(int test_case = 1; test_case <= 10 ; test_case++)
    {
        int word_length=0;
        cin >> word_length;
        string word = "";
        cin >> word;
        cout <<"#" <<test_case << " " <<f(word,word_length) << endl;
    }
 	return 0;   
}