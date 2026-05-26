#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	vector<vector<ll>> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			ll b = 0;
			cin >> b;
			v[i].push_back(b);
		}
		sort(v[i].begin(), v[i].end());
	}
	ll ans = 0;
	function<void(int, ll)> dfs = [&](int depth, ll p)
	{
		if (depth == n + 1)
		{
			ans += (x == p);
			return;
		}
		for (auto &i : v[depth])
		{
			if (p > x / i)
			{
				break;
			}
			dfs(depth + 1, p * i);
		}
	};
	dfs(1, 1);
	cout << ans;
	return 0;
}
