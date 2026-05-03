#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>>graph(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <= n; ++i)
		{
			graph[i].push_back(i);
		}
		int w = 0;
		cin >> w;
		vector<vector<char>>v(n + 1, vector<char>(w));
		for (int i = 1; i <= n; ++i)
		{
			for (auto& j : v[i])
			{
				cin >> j;
			}
		}
		vector<vector<int>>degree(n + 1, vector<int>(w));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				int nxt = (j + 1) % w;
				for (auto& k : graph[i])
				{
					if (v[k][nxt] == 'o')
					{
						degree[i][j]++;
					}
				}
			}
		}
		int ans = 0;
		queue<pii>q;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				ans += (v[i][j] == 'o');
				if (!degree[i][j] && v[i][j] == 'o')
				{
					q.push(make_pair(i, j));
				}
			}
		}
		while (!q.empty())
		{
			auto [ver, now] = q.front();
			q.pop();
			ans--;
			int pre = (now - 1 + w) % w;
			for (auto& i : graph[ver])
			{
				if (v[i][pre] == 'x')
				{
					continue;
				}
				if (--degree[i][pre] == 0)
				{
					q.push(make_pair(i, pre));
				}
			}
		}
		cout << ((ans) ? "Yes" : "No") << '\n';
	}
	return 0;
}
