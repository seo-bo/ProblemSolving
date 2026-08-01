#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void) // 조화수?
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int lim = 1e6;
	vector<int>v(lim + 5);
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		v[a] = i;
	}
	dsu p(n + 1);
	ll ans = 0;
	for (int i = lim; i >= 1; --i)
	{
		for (ll j = i, idx = -1; j <= lim; j += i)
		{
			if (!v[j])
			{
				continue;
			}
			if (idx == -1)
			{
				idx = v[j];
				continue;
			}
			if (!p.same(idx, v[j]))
			{
				p.merge(idx, v[j]);
				ans += i;
			}
		}
	}
	cout << ans;
	return 0;
}
