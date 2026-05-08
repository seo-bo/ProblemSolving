#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> color(n + 1, -1);
	ll ans = n * (n - 1) / 2 - m;
	for (int i = 1; i <= n; ++i)
	{
		if (color[i] != -1)
		{
			continue;
		}
		vector<ll> temp(2, 0);
		color[i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			temp[color[cur]]++;
			for (auto &i : graph[cur])
			{
				if (color[i] == color[cur])
				{
					cout << 0;
					return 0;
				}
				if (color[i] == -1)
				{
					color[i] = color[cur] ^ 1;
					q.push(i);
				}
			}
		}
		ans -= temp[0] * (temp[0] - 1) / 2 + temp[1] * (temp[1] - 1) / 2;
	}
	cout << ans;
	return 0;
}
