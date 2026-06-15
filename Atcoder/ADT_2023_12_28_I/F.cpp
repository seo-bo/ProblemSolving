#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0;
	cin >> n >> d;
	d *= d;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n; ++i)
	{
		auto [sx, sy] = v[i];
		for (int j = i + 1; j < n; ++j)
		{
			auto [ex, ey] = v[j];
			int p = (sx - ex) * (sx - ex) + (sy - ey) * (sy - ey);
			if (p <= d)
			{
				graph[i + 1].push_back(j + 1);
				graph[j + 1].push_back(i + 1);
			}
		}
	}
	vector<int>visited(n + 1);
	queue<int>q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (!visited[i])
			{
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ((visited[i]) ? "Yes" : "No") << '\n';
	}
	return 0;
}
