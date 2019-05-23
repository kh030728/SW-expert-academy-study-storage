//정점의 최대 수는 200을 넘지 않는다.
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int array[201];
int check(int index)
{
    if(array[index] == 0) // 값 없음
        return 0;
    if(array[index] == 1) // 숫자
    {
        if((index*2)+1 <=200)// 자식 노드가 존재할 수 있는 숫자 
        {
            if(array[index*2] == 0 && array[(index*2)+1] == 0) // 숫자에게 자식이 없는 경우
                return 1;
            return 0; // 자식이 있는 경우
        }
        return 1; // 자식노드가 존재할 수 없는 숫자의 경우
    }
    if(array[index] == 2) //기호
    {
        if((index*2)+1 <=200) // 기호에게 자식이 잇을 수 잇는 경우
            return check(index*2) * check((index*2)+1);
    }
    return 0; // 위 경우에 해당하지 않는 경우
}
int main(void)
{
    for(int test_case = 1; test_case <= 10 ; test_case++)
    {
        string tmp;
        getline(cin, tmp);
        int N;
        N = stoi(tmp);
        memset(array, 0, sizeof(array));
        for(int n = 1; n <= N; n++) //데이터 넣기
        {
       	 	string tmp;
        	getline(cin,tmp);
            stringstream ss(tmp);
            string str;
            ss>>str; ss >> str;
            if(str =="*" || str =="-" || str =="/" || str == "+")
            {
                array[n] = 2;
            }
            else
            {
                array[n] = 1;
            }
        }
        bool answer = false;
        cout << "#" <<test_case << " "<<check(1) <<endl;
        
    }
    return 0;
}