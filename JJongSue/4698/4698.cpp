#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
    int test=0;
    scanf("%d", &test);
    vector<int> prime;
    prime.push_back(2);
    for(int i=3;i<=1000000;i++)
    {
        bool is_prime=true;
        for(int j=0;j<prime.size();j++)
        {
            if(i >= prime[j]*prime[j] ) {
                if(i%prime[j] == 0)
                {
                    is_prime=false;
                    break;
                }
            }
            else{               
                break;
            }
        }
        if(is_prime)
        {
            prime.push_back(i);
            //printf("%d ", i);
        }
            
    }
    for(int test_i=1;test_i<=test;test_i++)
    {
        int D,A,B;
        scanf("%d %d %d", &D, &A, &B);
        int answer=0;
        for(int i=0;i<prime.size();i++)
        {
            if(prime[i] < A) continue;
            else if(prime[i] <= B){
                int tmp =prime[i];
                while(tmp != 0){
                    if(tmp%10 == D)
                    {
                        answer++;
                        break;
                    }
                    tmp=tmp/10;
                }
            }
            else{
                break;
            }
        }
        printf("#%d %d\n", test_i, answer);

    }
    

    return 0;
}