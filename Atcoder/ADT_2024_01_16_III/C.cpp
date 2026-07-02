#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	a--, b--;
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 0; i < a; ++i)
	{
		cout << str[i];
	}
	for (int i = b; i >= a; --i)
	{
		cout << str[i];
	}
	for (int i = b + 1; i < len; ++i)
	{
		cout << str[i];
	}
	return 0;
}
