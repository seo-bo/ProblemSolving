#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	auto bfs = [&](int start, int lim)
	{
		set<int> visited;
		visited.insert(start);
		queue<pii> q;
		q.push(make_pair(0, start));
		ll sum = 0;
		while (!q.empty())
		{
			auto [co, ver] = q.front();
			q.pop();
			sum += ver;
			if (co == lim)
			{
				continue;
			}
			for (auto &i : graph[ver])
			{
				if (visited.find(i) == visited.end())
				{
					visited.insert(i);
					q.push(make_pair(co + 1, i));
				}
			}
		}
		return sum;
	};
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
	return 0;
}
