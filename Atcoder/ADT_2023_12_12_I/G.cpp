#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<ll, ll> mm;
	mm[0] = 1;
	ll n = 0;
	cin >> n;
	function<ll(ll)> dfs = [&](ll now)
	{
		if (mm.find(now) != mm.end())
		{
			return mm[now];
		}
		ll pivot = dfs(now / 2) + dfs(now / 3);
		return mm[now] = pivot;
	};
	cout << dfs(n);
	return 0;
}
