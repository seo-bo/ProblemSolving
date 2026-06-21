#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	char a = '+';
	if (str.back() <= '2')
	{
		a = '-';
	}
	else if (str.back() <= '6')
	{
		a = ' ';
	}
	for (int i = 0; i < 2; ++i)
	{
		str.pop_back();
	}
	cout << str << a;
	return 0;
}
