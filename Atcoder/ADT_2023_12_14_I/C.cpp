#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n <= 999)
	{
		cout << n;
		return 0;
	}
	string str = to_string(n);
	for (ll i = 10000, j = 1;; i *= 10, ++j)
	{
		ll a = i - 1;
		if (n <= a)
		{
			int len = str.size();
			for (int k = 1; k <= j; ++k)
			{
				str[len - k] = '0';
			}
			cout << str;
			return 0;
		}
	}
	return 0;
}
