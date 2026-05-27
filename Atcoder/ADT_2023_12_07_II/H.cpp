#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, set<int>> x, y;
	int h = 0, w = 0, n = 0, cnt = 1;
	cin >> h >> w >> n;
	map<pii, int> pos;
	vector<tp> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto &[a, b, c] = v[i];
		cin >> a >> b >> c;
		if (x.find(a) == x.end() || x[a].find(c) == x[a].end())
		{
			x[a].insert(c);
			pos[make_pair(a, c)] = cnt++;
		}
		if (y.find(b) == y.end() || y[b].find(c) == y[b].end())
		{
			y[b].insert(c);
			pos[make_pair(-b, c)] = cnt++;
		}
	}
	vector<vector<int>> graph(cnt + 10);
	vector<int> degree(cnt + 10);
	for (int i = 1; i <= n; ++i)
	{
		auto &[a, b, c] = v[i];
		auto it = x[a].lower_bound(c);
		auto jt = y[b].lower_bound(c);
		int base1 = pos[make_pair(a, c)], base2 = pos[make_pair(-b, c)];
		if (it != x[a].begin())
		{
			--it;
			int ver = pos[make_pair(a, *it)];
			graph[base1].push_back(ver);
			graph[base2].push_back(ver);
			degree[ver] += 2;
		}
		if (jt != y[b].begin())
		{
			--jt;
			int ver = pos[make_pair(-b, *jt)];
			graph[base1].push_back(ver);
			graph[base2].push_back(ver);
			degree[ver] += 2;
		}
	}
	vector<int> dp(cnt + 1);
	queue<int> q;
	for (int i = 1; i <= cnt; ++i)
	{
		if (!degree[i])
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto &i : graph[cur])
		{
			dp[i] = max(dp[i], dp[cur] + 1);
			if (--degree[i] == 0)
			{
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		auto &[a, b, c] = v[i];
		int v1 = pos[make_pair(a, c)], v2 = pos[make_pair(-b, c)];
		cout << max(dp[v1], dp[v2]) << '\n';
	}
	return 0;
}
