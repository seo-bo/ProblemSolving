#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll> cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	vector<vector<pll>> graph(n + 1, vector<pll>(n + 1, make_pair(LLONG_MAX, LLONG_MIN)));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			char a;
			cin >> a;
			if (i == j)
			{
				graph[i][i] = make_pair(0, cost[i]);
				continue;
			}
			if (a == 'N')
			{
				continue;
			}
			graph[i][j] = make_pair(1, cost[i] + cost[j]);
		}
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][k].first == LLONG_MAX || graph[k][j].first == LLONG_MAX)
				{
					continue;
				}
				ll cnt = graph[i][k].first + graph[k][j].first;
				ll co = graph[i][k].second + graph[k][j].second - cost[k];
				if (graph[i][j].first > cnt)
				{
					graph[i][j] = make_pair(cnt, co);
				}
				else if (graph[i][j].first == cnt && graph[i][j].second < co)
				{
					graph[i][j].second = co;
				}
			}
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		auto [aa, bb] = graph[a][b];
		if (aa == LLONG_MAX)
		{
			cout << "Impossible" << '\n';
			continue;
		}
		cout << aa << ' ' << bb << '\n';
	}
	return 0;
}
