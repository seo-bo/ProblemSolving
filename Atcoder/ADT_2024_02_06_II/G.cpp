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
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<ll>prefix(n + 2), suffix(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		int idx = n - i + 1;
		prefix[i] = min(prefix[i - 1] + v[i], l * i);
		suffix[idx] = min(suffix[idx + 1] + v[idx], r * i);
	}
	ll ans = prefix[n];
	for (int i = 1; i <= n; ++i)
	{
		ans = min(ans, prefix[i - 1] + suffix[i]);
	}
	cout << ans;
	return 0;
}
