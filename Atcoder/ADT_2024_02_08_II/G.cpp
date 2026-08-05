#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n + 1);
	vector<ll>p(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [x, y] = v[i];
		cin >> x >> y >> p[i];
	}
	vector<vector<ll>>graph(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		auto [ax, ay] = v[i];
		for (int j = 1; j <= n; ++j)
		{
			auto [bx, by] = v[j];
			graph[i][j] = (llabs(ax - bx) + llabs(ay - by) + p[i] - 1) / p[i];
		}
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
			}
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		ll temp = 0;
		for (int j = 1; j <= n; ++j)
		{
			temp = max(temp, graph[i][j]);
		}
		ans = min(ans, temp);
	}
	cout << ans;
	return 0;
}
