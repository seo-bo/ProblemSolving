#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	ll ans = LLONG_MAX;
	for (ll i = 1; i * i <= b * 100; ++i)
	{
		ll pivot = (b + i - 1) / i;
		if (i <= a && pivot <= a)
		{
			ans = min(ans, i * pivot);
		}
	}
	cout << ((ans == LLONG_MAX) ? -1 : ans);
	return 0;
}
