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
	reverse(str.begin(), str.end());
	ll x = 0, base = 0, len = str.size();
	cin >> x;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '1')
		{
			base |= (1LL << i);
		}
	}
	if (base > x)
	{
		cout << -1;
		return 0;
	}
	for (int i = len - 1; i >= 0; --i)
	{
		ll t = (1LL << i);
		if (str[i] == '?' && base <= x - t)
		{
			base |= t;
		}
	}
	cout << base;
	return 0;
}
