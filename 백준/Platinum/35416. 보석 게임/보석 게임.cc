#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int r = 0, k = 0;
	cin >> r >> k;
	vector<vector<ll>>v(r + 3, vector<ll>(k + 1));
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			cin >> v[i][j];
			v[i][j] *= ((i & 1) ? 1 : -1);
		}
	}
	vector<ll>dp(k + 1);
	for (int i = r; i >= 2; --i)
	{
		vector<pll>temp;
		auto cal = [&](int row, int idx)
			{
				auto [fc, fx] = temp.front();
				if (fx == idx)
				{
					fc -= v[row][idx];
				}
				ll sc = ((row & 1) ? LLONG_MIN : LLONG_MAX), sx = -1;
				if (temp.size() > 1)
				{
					sc = temp[1].first, sx = temp[1].second;
				}
				if (row & 1)
				{
					if (fc > sc)
					{
						return make_pair(fc, fx);
					}
					return make_pair(sc, sx);
				}
				if (fc < sc)
				{
					return make_pair(fc, fx);
				}
				return make_pair(sc, sx);
			};
		for (int j = 1; j <= k; ++j)
		{
			temp.push_back(make_pair(v[i][j] + dp[j], j));
		}
		if (i & 1)
		{
			sort(temp.rbegin(), temp.rend());
		}
		else
		{
			sort(temp.begin(), temp.end());
		}
		vector<ll>nxt = dp;
		for (int j = 1; j <= k; ++j)
		{
			auto [co, idx] = cal(i, j);
			if (i & 1)
			{
				nxt[j] = max(nxt[j], co);
			}
			else
			{
				nxt[j] = min(nxt[j], co);
			}
		}
		dp = move(nxt);
	}
	ll ans = LLONG_MIN;
	for (int i = 1; i <= k; ++i)
	{
		ans = max(ans, v[1][i] + dp[i]);
	}
	cout << ((ans > 0) ? "djangg7" : "ibasic") << ' ' << llabs(ans);
	return 0;
}