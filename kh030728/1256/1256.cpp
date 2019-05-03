#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
 	int test_case;
    cin >> test_case;
    
    for(int T = 1; T <= test_case ; T++)
    {
        int targetIndex;
        string word;
        vector<string> v;
        cin >> targetIndex >> word;
        int l = word.length();
        for(int i = 0; i < l ;i++)
        {
        	v.push_back(word);
            word.erase(0,1);
        }
        sort(v.begin(),v.end());
       
     	cout << "#"<<T<<" "<<v.at(targetIndex-1) << endl;   
    }
    
    return 0;
}