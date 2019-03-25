#include<iostream>
using namespace std;
int main(void){
    int input_number;
    cin >> input_number;
    for(int i=1;i <= input_number; i++)
    {
        int i_switch=1, i_num=i;
        while(i_num)
        {
            if(i_num%10 == 3 || i_num%10 == 6 || i_num%10==9)
            {
                cout << "-";
                i_switch=0;
            }
            i_num/=10;
            
        }
        if(i_switch) cout << i;
        cout << " ";
    }
    return 0;
}