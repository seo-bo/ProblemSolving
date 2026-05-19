#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<pii, map<ll, ll>> left, right;
	vector<vector<ll>> v(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>> dir = {{1, 0}, {0, 1}};
	function<void(int, int, int, int, ll)> dfs = [&](int depth, int p, int x, int y, ll res)
	{
		res ^= v[x][y];
		if (depth == n - 1)
		{
			pii pos = make_pair(x, y);
			if (p == 1)
			{
				left[pos][res]++;
			}
			else
			{
				right[pos][res]++;
			}
			return;
		}
		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dir[i][0] * p;
			int ny = y + dir[i][1] * p;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				dfs(depth + 1, p, nx, ny, res);
			}
		}
	};
	dfs(0, 1, 1, 1, 0);
	dfs(0, -1, n, n, 0);
	ll ans = 0;
	for (auto &[pos, i] : left)
	{
		auto [x, y] = pos;
		for (auto &[a, b] : i)
		{
			ll temp = (a ^ v[x][y]);
			if (right.find(pos) != right.end() && right[pos].find(temp) != right[pos].end())
			{
				ans += b * right[pos][temp];
			}
		}
	}
	cout << ans;
	return 0;
}
