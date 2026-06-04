#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll h = 0, w = 0, sx = 0, sy = 0, n = 0;
	cin >> h >> w >> sx >> sy >> n;
	map<ll, vector<ll>> x, y;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		x[a].push_back(b);
		y[b].push_back(a);
	}
	for (auto &[a, b] : x)
	{
		sort(b.begin(), b.end());
	}
	for (auto &[a, b] : y)
	{
		sort(b.begin(), b.end());
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		char a;
		ll b = 0;
		cin >> a >> b;
		if (a == 'L' || a == 'R')
		{
			auto it = upper_bound(x[sx].begin(), x[sx].end(), sy);
			if (a == 'R')
			{
				if (it == x[sx].end())
				{
					sy = min(w, sy + b);
				}
				else
				{
					ll p = *it - 1;
					sy = min(p, sy + b);
				}
			}
			else
			{
				if (it == x[sx].begin())
				{
					sy = max(1LL, sy - b);
				}
				else
				{
					ll p = *(--it) + 1;
					sy = max(p, sy - b);
				}
			}
		}
		else
		{
			auto it = upper_bound(y[sy].begin(), y[sy].end(), sx);
			if (a == 'D')
			{
				if (it == y[sy].end())
				{
					sx = min(h, sx + b);
				}
				else
				{
					ll p = *it - 1;
					sx = min(p, sx + b);
				}
			}
			else
			{
				if (it == y[sy].begin())
				{
					sx = max(1LL, sx - b);
				}
				else
				{
					ll p = *(--it) + 1;
					sx = max(p, sx - b);
				}
			}
		}
		cout << sx << ' ' << sy << '\n';
	}
	return 0;
}
