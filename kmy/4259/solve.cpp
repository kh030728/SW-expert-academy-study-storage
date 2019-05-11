#include<iostream>
#include <cmath>
using namespace std;
int print_int128(__int128 n) {
  if (n == 0)  return printf("0\n");

  char str[40] = {0}; // log10(1 << 128) + '\0'
  char *s = str + sizeof(str) - 1; // start at the end
  while (n != 0) {
    if (s == str) return -1; // never happens

    *--s = "0123456789"[n % 10]; // save last digit
    n /= 10;                     // drop it
  }
  return printf("%s", s);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        __int128 sum = 0;
        cin>>N;

        for(int i=0; i<N; i++)
        {
            int x;
            cin>>x;
            __int128 tmp = 1;
            int q = int(x/10);
            for(int j=0; j<int(x%10); j++){
                tmp *= q;
            }
            sum += tmp;
        }

		cout<<"#"<<test_case<<" ";
		print_int128(sum);
        cout<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}