#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	vector<int>sw(n + 1);
	for (int i = 0; i < k; ++i)
	{
		int a = 0;
		cin >> a;
		sw[a] = 1;
	}
	vector<vector<int>>visited(n + 1, vector<int>(2, INT_MAX));
	deque<pii>dq;
	visited[1][1] = 0;
	dq.push_back(make_pair(1, 1));
	while (!dq.empty())
	{
		auto [ver, now] = dq.front();
		dq.pop_front();
		if (sw[ver])
		{
			int nxt = now ^ 1;
			if (visited[ver][nxt] > visited[ver][now])
			{
				visited[ver][nxt] = visited[ver][now];
				dq.push_front(make_pair(ver, nxt));
			}
		}
		for (auto& [a, b] : graph[ver])
		{
			if (now != b)
			{
				continue;
			}
			if (visited[a][b] > visited[ver][now] + 1)
			{
				visited[a][b] = visited[ver][now] + 1;
				dq.push_back(make_pair(a, b));
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i <= 1; ++i)
	{
		ans = min(ans, visited[n][i]);
	}
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}
