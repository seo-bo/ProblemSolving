#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> ver(m + 1);
	vector<vector<int>> v(n + 1);
	vector<int> dist(n + 1, INT_MAX);
	vector<bool> fin(n + 1), visited(m + 1);
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			ver[b].push_back(i);
			v[i].push_back(b);
			if (b == 1)
			{
				dist[i] = 0;
				q.push(i);
			}
			if (b == m)
			{
				fin[i] = true;
			}
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (fin[cur])
		{
			cout << dist[cur];
			return 0;
		}
		for (auto &i : v[cur])
		{
			if (visited[i])
			{
				continue;
			}
			for (auto &j : ver[i])
			{
				if (dist[j] > dist[cur] + 1)
				{
					dist[j] = dist[cur] + 1;
					q.push(j);
				}
			}
			visited[i] = true;
		}
	}
	cout << -1;
	return 0;
}
