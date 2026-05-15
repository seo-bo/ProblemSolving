#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int s = 0, t = 0, m = 0;
	cin >> s >> t >> m;
	vector<vector<int>> graph(s + t + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int pivot = -1;
	auto bfs = [&](int start)
	{
		queue<pii> q;
		vector<int> cnt(t + 1);
		q.push(make_pair(0, start));
		while (!q.empty())
		{
			auto [co, ver] = q.front();
			q.pop();
			if (co == 2)
			{
				cnt[ver - s]++;
				continue;
			}
			for (auto &i : graph[ver])
			{
				if (co)
				{
					if (i == start)
					{
						continue;
					}
					q.push(make_pair(2, i));
				}
				else
				{
					q.push(make_pair(1, i));
				}
			}
		}
		for (int i = 1; i <= t; ++i)
		{
			if (s + i == start)
			{
				continue;
			}
			if (cnt[i] >= 2)
			{
				pivot = i + s;
				break;
			}
		}
	};
	for (int i = 1; i <= t; ++i)
	{
		bfs(s + i);
		if (pivot != -1)
		{
			int a = s + i, b = pivot;
			cout << a << ' ' << b << ' ';
			vector<bool> flag(s + 1);
			for (auto &j : graph[a])
			{
				flag[j] = true;
			}
			int cnt = 0;
			for (auto &j : graph[b])
			{
				if (flag[j])
				{
					cout << j << ' ';
					if (++cnt == 2)
					{
						break;
					}
				}
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}
