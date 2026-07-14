#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>parent(n + 1, -1);
	auto bfs = [&](int node)
		{
			vector<int>dist(n + 1, INT_MAX);
			dist[node] = 0;
			queue<int>q;
			q.push(node);
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto& i : graph[cur])
				{
					if (dist[i] > dist[cur] + 1)
					{
						dist[i] = dist[cur] + 1;
						parent[i] = cur;
						q.push(i);
					}
				}
			}
			int idx = -1, pivot = -1;
			for (int i = 1; i <= n; ++i)
			{
				if (pivot < dist[i])
				{
					pivot = dist[i];
					idx = i;
				}
			}
			int d = pivot, mid1 = idx;
			for (int i = 0; i < d / 2; ++i)
			{
				mid1 = parent[mid1];
			}
			int mid2 = mid1;
			if (d % 2)
			{
				mid2 = parent[mid1];
			}
			return make_tuple(mid1, mid2, idx, d);
		};
	auto [_, __, sx, ___] = bfs(1);
	auto [mid1, mid2, ex, dist] = bfs(sx);
	auto sv = [&](int start, int ban)
		{
			vector<ll>cnt(1, 0);
			int p = 0;
			function<void(int, int, int)> dfs = [&](int parent, int node, int depth)
				{
					if (depth == dist / 2)
					{
						cnt[p]++;
						return;
					}
					for (auto& i : graph[node])
					{
						if (i == parent || i == ban)
						{
							continue;
						}
						if (node == start)
						{
							cnt.push_back(0);
							p++;
						}
						dfs(node, i, depth + 1);
					}
				};
			dfs(0, start, 0);
			return cnt;
		};
	vector<ll>left = sv(mid1, mid2);
	if (dist % 2 == 0)
	{
		ll ans = 1, p = 0;
		for (auto& i : left)
		{
			ans = (ans * (i + 1)) % MOD; // 안고르는거까지
			p = (p + i) % MOD;
		}
		cout << (ans - 1 + MOD - p + MOD) % MOD; // 전체 - 0개 고르기 - 1개 고르기
		return 0;
	}
	vector<ll>right = sv(mid2, mid1);
	ll l = 0, r = 0;
	for (auto& i : left)
	{
		l = (l + i) % MOD;
	}
	for (auto& i : right)
	{
		r = (r + i) % MOD;
	}
	cout << l * r % MOD;
	return 0;
}
