#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, h1 = 0, w1 = 0, h2 = 0, w2 = 0;
	cin >> n >> m >> h1 >> w1 >> h2 >> w2;
	vector<vector<ll>> prefix(n + 1, vector<ll>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			ll a = 0;
			cin >> a;
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a;
		}
	}
	auto query = [&](int x1, int y1, int x2, int y2)
	{
		x2 = min(x2, n), y2 = min(y2, m);
		return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
	};
	int x = min(h1, h2), y = min(w1, w2);
	vector<vector<ll>> maxi(n + 1, vector<ll>(m + 1));
	for (int i = 1; i + x - 1 <= n; ++i)
	{
		deque<pll> dq;
		for (int j = 1, p = 1; j + w1 - 1 <= m; ++j)
		{
			while (!dq.empty() && dq.front().second < j)
			{
				dq.pop_front();
			}
			while (p + y - 1 <= m && p + y - 1 <= j + w1 - 1)
			{
				ll cost = query(i, p, i + x - 1, p + y - 1);
				while (!dq.empty() && dq.back().first <= cost)
				{
					dq.pop_back();
				}
				dq.push_back(make_pair(cost, p++));
			}
			maxi[i][j] = dq.front().first;
		}
	}
	vector<vector<ll>> ans(n + 1, vector<ll>(m + 1));
	for (int i = 1; i + w1 - 1 <= m; ++i)
	{
		deque<pll> dq;
		for (int j = 1, p = 1; j + h1 - 1 <= n; ++j)
		{
			while (!dq.empty() && dq.front().second < j)
			{
				dq.pop_front();
			}
			while (p + x - 1 <= n && p + x - 1 <= j + h1 - 1)
			{
				ll cost = maxi[p][i];
				while (!dq.empty() && dq.back().first <= cost)
				{
					dq.pop_back();
				}
				dq.push_back(make_pair(cost, p++));
			}
			ans[j][i] = dq.front().first;
		}
	}
	ll res = 0;
	for (int i = 1; i + h1 - 1 <= n; ++i)
	{
		for (int j = 1; j + w1 - 1 <= m; ++j)
		{
			res = max(res, query(i, j, i + h1 - 1, j + w1 - 1) - ans[i][j]);
		}
	}
	cout << res;
	return 0;
}
