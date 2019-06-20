#include <iostream>
using namespace std;
class node
{
    public:
    node *prev = NULL;
    int data = 0;
};
class stack
{
    node *top = NULL;
    int size = 0;
    public:
    void push(int elem)
    {
        size++;
        if(top == NULL)
        {
            top = (node*)malloc(sizeof(node));
            top->data = elem;
        }
        else
        {
            node *tmp = (node*)malloc(sizeof(node));
            tmp->data = elem;
            tmp->prev = top;
            top = tmp;
        }
    }
    void pop()
    {
        if(size > 0)
        {
            size--;
            cout << top->data << endl;
            node *tmp = top;
            top = top->prev;
            //free(tmp);
        }
        else
            cout << "-1" << endl;
    }
    void Top()
    {
        if(size > 0)
            cout << top->data << endl;
        else
            cout << "-1" << endl;
    }
    void Size()
    {
        if(size > 0)
            cout << size << endl;
        else
            cout << "0" << endl;
    }
    void empty()
    {
        if(size > 0)
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
            stck.Top();
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