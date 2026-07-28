#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	ll ans = LLONG_MAX, p = sqrt(m) + 10;
	for (ll i = 1; i <= p && i <= n; ++i)
	{
		ll temp = (m + i - 1) / i;
		if (temp > n)
		{
			continue;
		}
		ans = min(ans, temp * i);
	}
	cout << ((ans == LLONG_MAX) ? -1 : ans);
	return 0;
}
