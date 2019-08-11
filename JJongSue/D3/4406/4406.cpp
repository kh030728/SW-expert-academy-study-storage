#include<iostream>
#include<string>
using namespace std;
int main(void)
{
    int test;
    scanf("%d", &test);
    for(int test_i=1;test_i<=test;test_i++)
    {
        string tmp;
        cin >> tmp;
        string answer="";
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]!='a' && tmp[i]!='e' && tmp[i]!='i'
            && tmp[i]!='o' && tmp[i]!='u')
            answer+=tmp[i];
        }
        cout << "#" << test_i << " " << answer << endl;
    }
    return 0;
}