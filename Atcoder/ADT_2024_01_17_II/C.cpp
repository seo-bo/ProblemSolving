#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0;
	cin >> a;
	if (a == 1)
	{
		cout << 1;
		return 0;
	}
	if (a == 4)
	{
		cout << 2;
		return 0;
	}
	for (ll i = 3; i * i * i <= a; ++i)
	{
		ll temp = 1;
		for (ll j = 1; j <= i; ++j)
		{
			if (temp > a / j)
			{
				temp = -1;
				break;
			}
			temp *= i;
		}
		if (temp == a)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
