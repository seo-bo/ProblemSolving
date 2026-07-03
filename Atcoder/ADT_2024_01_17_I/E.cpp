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
	vector<ll> v(n), prefix(n);
	for(auto & i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; ++i)
	{
		prefix[i] += prefix[i - 1] + v[i] - v[i - 1];
	}
	ll ans = 0;
	for (int i = 0; i <= n; ++i)
	{
		ll it = lower_bound(prefix.begin(), prefix.end(), prefix[i] + m) - prefix.begin();
		ans = max(ans, it - i);
	}
	cout << ans;
	return 0;
}
