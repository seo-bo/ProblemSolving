#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll BIT[300002];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>p(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}
	vector<vector<int>>color(n + 1);
	auto update = [&](int idx, int delta)
		{
			while (idx <= n)
			{
				BIT[idx] += delta;
				idx += idx & -idx;
			}
		};
	auto query = [&](int idx)
		{
			ll res = 0;
			while (idx)
			{
				res += BIT[idx];
				idx -= idx & -idx;
			}
			return res;
		};
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		ans += query(n) - query(a);
		update(a, 1);
		color[p[i]].push_back(a);
	}
	memset(BIT, 0, sizeof(BIT));
	for (auto& i : color)
	{
		for (auto& j : i)
		{
			ans -= query(n) - query(j);
			update(j, 1);
		}
		for (auto& j : i)
		{
			update(j, -1);
		}
	}
	cout << ans;
	return 0;
}
