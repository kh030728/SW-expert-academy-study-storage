//정점의 총수는 100을 넘지 않는다.
#include <iostream>
#include <cstring>
using namespace std;
char array[101];
//print함수는 중위 순회를 구현한 것이다.
//자신에게 값이 있는경우 자신보다 좌측 자식을 먼저 확인하고 자신의 값을 보여준후 우측 자식의 값을 보여준다.
void print(int index)
{
    if(array[index] != 0)
    {
        print(index*2);
        cout << array[index];
        print((index*2)+1);
    }
}
int main(void)
{
    for(int T = 1; T <= 10 ; T++)
    {
        int N;
        cin >> N;
        char tmp;
        memset(array,0,sizeof(array));
        // 자료 읽어오기
        for(int n = 1; n <= N; n++) // 여기서 n은 문자를 읽은 수이며 넣을 배열의 인덱스이다.
        {
            cin >> tmp;
            if('A' <= tmp && tmp <= 'Z' || tmp == '_') //['A'-'Z']와 '_'만이 문자로 들어온다.
                array[n] = tmp;
            else
                n -= 1; // 문자를 넣지 못했기 때문에 -1을 해준다.
        }
        cout << "#" << T << " "; print(1); cout<<endl;
    }
    
    return 0;
}