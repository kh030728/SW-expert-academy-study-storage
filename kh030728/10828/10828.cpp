#include <iostream>
using namespace std;
class stack
{
    int st[100000];
    int size = -1;
    public:
    void push(int elem)
    {
        size++;
        st[size] = elem;
    }
    void pop()
    {
        if(size > -1)
        {
            cout << st[size]<< endl;
            st[size] = 0;
            size--;
        }
        else
            cout << "-1" << endl;
    }
    void top()
    {
        if(size > -1)
            cout << st[size] << endl;
        else
            cout << "-1" << endl;
    }
    void Size()
    {
        if(size > -1)
            cout << size+1 << endl;
        else
            cout << "0" << endl;
    }
    void empty()
    {
        if(size > -1)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    
};
int main(void)
{
    int test_case;
    stack stck;
    cin >> test_case;
    for(int T = 0; T < test_case; T++)
    {
        string command;
        int num = 0;
        cin >> command;
        if(command == "push")
        {
            cin >> num;
            stck.push(num);
        }
        else if(command == "top")
        {
            stck.top();
        }
        else if(command == "size")
        {
            stck.Size();
        }
        else if(command == "pop")
        {
            stck.pop();
        }
        else if(command == "empty")
        {
            stck.empty();
        }
    }
    
    return 0;
}