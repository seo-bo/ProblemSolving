#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<ll, ll>mm;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		mm[a]++;
	}
	ll ans = 0;
	for (ll i = 1; i <= 200000; ++i)
	{
		for (ll j = 1; i * j <= 200000; ++j)
		{
			ans += mm[i] * mm[j] * mm[i * j];
		}
	}
	cout << ans;
	return 0;
}
