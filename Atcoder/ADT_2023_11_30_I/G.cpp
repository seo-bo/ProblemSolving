#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, l = 0, r = 0;
	cin >> n >> l >> r;
	vector<ll> v(n + 1), prefix(n + 3), suffix(n + 3);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		prefix[i] = min(prefix[i - 1] + v[i], l * i);
	}
	for (int i = n; i >= 1; --i)
	{
		suffix[i] = min(suffix[i + 1] + v[i], r * (n - i + 1));
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i <= n; ++i)
	{
		ans = min(ans, prefix[i] + suffix[i + 1]);
	}
	cout << ans;
	return 0;
}
