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
	vector<vector<ll>> v(n);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			ll b = 0;
			cin >> b;
			v[i].push_back(b);
		}
	}
	ll ans = 0;
	function<void(int, ll, ll)> dfs = [&](int depth, ll mul, ll sum)
	{
		if (depth == n)
		{
			if (!sum)
			{
				return;
			}
			ans += (mul == x);
			return;
		}
		for (auto &i : v[depth])
		{
			if (mul > x / i)
			{
				continue;
			}
			dfs(depth + 1, mul * i, sum + i);
		}
	};
	dfs(0, 1, 0);
	cout << ans;
	return 0;
}
