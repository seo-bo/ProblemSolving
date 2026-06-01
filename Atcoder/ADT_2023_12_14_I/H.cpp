#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353
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
	vector<bool> visited(n + 1);
	ll ans = 1;
	auto bfs = [&](int node)
	{
		int cnt = 0;
		set<pii> s;
		queue<int> q;
		q.push(node);
		visited[node] = true;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cnt++;
			for (auto &i : graph[cur])
			{
				int a = cur, b = i;
				if (a > b)
				{
					swap(a, b);
				}
				s.insert(make_pair(a, b));
				if (!visited[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}
		if (cnt == s.size())
		{
			return 2;
		}
		return 0;
	};
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			ans = (ans * bfs(i)) % MOD;
		}
	}
	cout << ans;
	return 0;
}
