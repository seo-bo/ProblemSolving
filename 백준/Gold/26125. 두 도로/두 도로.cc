#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, s = 0, t = 0;
	cin >> n >> m >> s >> t;
	vector<vector<ll>>graph(n + 1, vector<ll>(n + 1, INT_MAX));
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	auto cal = [&]
		{
			int s1 = 0, e1 = 0, c1 = 0, s2 = 0, e2 = 0, c2 = 0;
			ll res = graph[s][t];
			cin >> s1 >> e1 >> c1 >> s2 >> e2 >> c2;
			res = min({ res, graph[s][s1] + graph[e1][t] + c1, graph[s][s2] + graph[e2][t] + c2 });
			res = min({ res, graph[s][s1] + graph[e1][s2] + graph[e2][t] + c1 + c2, graph[s][s2] + graph[e2][s1] + graph[e1][t] + c1 + c2 });
			return ((res == INT_MAX) ? -1 : res);
		};
	int q = 0;
	cin >> q;
	while (q--)
	{
		cout << cal() << '\n';
	}
	return 0;
}