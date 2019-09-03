#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long gcd(long a, long b){
	while(b!=0)
	{
		long r = a%b;
		a = b;
		b = r;
	}
	return a;
}
long long lcm(long a, long b){
	return a*b/gcd(a,b);
}
int main(int argc, char** argv)
{
	string s, t;
	cin>>s;
	cin>>t;
	string tmp1, tmp2;
	long long ll = lcm(s.size(), t.size());
	for(long i=0; i<ll/s.size(); i++)
	{
		tmp1 += s;
	}
	for(long i=0; i<ll/t.size(); i++)
	{
		tmp2 += t;
	}
	if(tmp1 == tmp2)
		cout<<1;
	else
		cout<<0;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}