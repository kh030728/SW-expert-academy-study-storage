#include<iostream>
#include<vector>

using namespace std;
int main(void)
{
    int test=0;
    vector<int> prime;
    prime.push_back(2);
    for(int i=3;i<1000000;i++)
    {
        bool is_prime=true;
        for(int j=0;j<prime.size();j++)
        {
            if(i >= prime[j]*prime[j])
            {
                if(i%prime[j] == 0)
                {
                    is_prime=false;
                    break;
                }
            }
            if(is_prime)
            {
                prime.push_back(i);
            }
        }
    }
    for(int test_i=1;test_i<=test;test_i++)
    {
        int tmp;
        vector<int> number;
        for(int i=0;i<10;i++)
        {
            scanf("%d", &tmp);
            if(tmp == 1) number.push_back(i);
        }
        
    }

    return 0;
}