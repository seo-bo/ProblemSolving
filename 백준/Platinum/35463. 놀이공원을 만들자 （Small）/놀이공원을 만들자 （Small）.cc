#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, mini = INT_MAX, maxi = INT_MIN;
	cin >> n >> m;
	vector<pii>time(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = time[i];
		cin >> a >> b;
		mini = min(mini, b), maxi = max(maxi, b);
	}
	vector<vector<pii>>g1(n + 1), g2(n + 1);
	vector<int>weight(m + 1);
	for (int i = 1; i <= m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		auto [A, B] = time[b];
		g1[a].push_back(make_pair(b, A + B + c));
		g2[a].push_back(make_pair(b, A + B));
		weight[i] = c;
	}
	sort(weight.begin(), weight.end());
	for (int i = 1; i <= m; ++i)
	{
		weight[i] += weight[i - 1];
	}
	auto dijkstra = [&](vector<vector<pii>>& graph, int d)
		{
			vector<vector<int>>dist(n + 1, vector<int>(n + 1, INT_MAX));
			priority_queue<tp, vector<tp>, greater<tp>>pq;
			for (int i = 1; i <= n; ++i)
			{
				auto [A, B] = time[i];
				if (B == mini)
				{
					pq.push(make_tuple(A + B, 0, i));
					dist[i][0] = A + B;
				}
			}
			while (!pq.empty())
			{
				auto [co, cnt, ver] = pq.top();
				pq.pop();
				if (dist[ver][cnt] < co || cnt == n)
				{
					continue;
				}
				for (auto& [nv, nc] : graph[ver])
				{
					if (dist[nv][cnt + d] > co + nc)
					{
						dist[nv][cnt + d] = co + nc;
						pq.push(make_tuple(co + nc, cnt + d, nv));
					}
				}
			}
			int res = INT_MAX;
			for (int i = 1; i <= n; ++i)
			{
				if (time[i].second != maxi)
				{
					continue;
				}
				for (int j = 0; j <= min(n, m); ++j)
				{
					if (dist[i][j] == INT_MAX)
					{
						continue;
					}
					res = min(res, dist[i][j] + ((d == 1) ? weight[j] : 0));
				}
			}
			return res;
		};
	int a = dijkstra(g1, 0), b = dijkstra(g2, 1);
	cout << ((a == INT_MAX) ? -1 : a - b);
	return 0;
}