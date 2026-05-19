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
	map<ll, ll> mm;
	for (ll i = 1; i * i <= n; ++i)
	{
		for (ll j = i; i * j <= n; ++j)
		{
			mm[i * j] += 2 - (i == j);
		}
	}
	ll ans = 0;
	for (auto &[a, b] : mm)
	{
		ans += mm[a] * mm[n - a];
	}
	cout << ans;
	return 0;
}
