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
	vector<vector<ll>>v(n + 1);
	vector<vector<ll>>prefix(n + 5, vector<ll>(1));
	ll ans = 0, tot = 0;
	for (ll i = 1; i <= n; ++i)
	{
		ll a = 0, right = n - i + 1;
		cin >> a;
		ll it = upper_bound(v[a].begin(), v[a].end(), right) - v[a].begin();
		it = prefix[a][it] + (v[a].size() - it) * right;
		ans += tot - it;
		tot -= max(0LL, i - right);
		tot += min(i, right - 1);
		v[a].push_back(i);
		prefix[a].push_back(prefix[a].back() + i);
	}
	cout << ans;
	return 0;
}
