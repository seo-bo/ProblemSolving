#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>dist(n + 1, vector<ll>(n + 1, LLONG_MAX / 8));
	vector<tp>edge(m);
	for (auto& [a, b, c] : edge)
	{
		cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}
	for (int i = 1; i <= n; ++i)
	{
		dist[i][i] = 0;
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	for (auto& [v1, v2, co] : edge)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i == v1 || i == v2)
			{
				continue;
			}
			if (dist[v1][i] + dist[i][v2] <= co)
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
