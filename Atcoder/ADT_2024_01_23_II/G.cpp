#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll> v(n + 10);
	iota(v.begin(), v.end(), 0);
	for (ll i = 2; i * i <= n; ++i)
	{
		ll k = i * i;
		for (ll j = k; j <= n; j += k)
		{
			while (v[j] % k == 0)
			{
				v[j] /= k;
			}
		}
	}
	vector<ll> cnt(n + 10);
	for (int i = 1; i <= n; ++i)
	{
		cnt[v[i]]++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += cnt[i] * cnt[i];
	}
	cout << ans;
	return 0;
}
