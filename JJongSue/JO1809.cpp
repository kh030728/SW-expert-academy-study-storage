#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(void)
{

    int N = 0;
    scanf("%d", &N);
    stack <long> ls;
    stack <int> numS;
    long tmp;
    for(int i=1;i<=N;i++)
    {
        scanf("%ld", &tmp);
        if(ls.empty())
        {
            printf("0 ");
            ls.push(tmp);
            numS.push(i);
        }            
        else{
            if(ls.top() >= tmp){
                printf("%d ", numS.top());
                ls.push(tmp);
                numS.push(i);
            }
            else{
                while(ls.empty() == false)
            {
                if(ls.top() >= tmp) break;
                ls.pop();
                numS.pop();
            }
             if(ls.empty())
            {
                printf("0 ");
                ls.push(tmp);
                numS.push(i);
            }
            else{
                printf("%d ", numS.top());
                ls.push(tmp);
                numS.push(i);
            }
            
         
        }
        }
        
    }
/*
    vector<long> a(N+1,0);
    vector<long> b(N+1,0);
    a[0] = 100000001;
    b[0] = 0;
    for(int i=1;i<=N;i++)
    {
        scanf("%ld", &a[i]);
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>=a[i])
            {
                b[i] =j;
                printf("%d ", j);
            break;
            }
            else{
                j=b[j];
            }
            
        }

    }*/
    
    return 0;
}