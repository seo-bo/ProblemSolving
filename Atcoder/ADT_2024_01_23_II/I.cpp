#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[--a].push_back(--b);
		graph[b].push_back(a);
	}
	vector<vector<int>>visited(n, vector<int>(1 << n, INT_MAX));
	queue<pii>q;
	for (int i = 0; i < n; ++i)
	{
		visited[i][1 << i] = 1;
		q.push(make_pair(i, 1 << i));
	}
	while (!q.empty())
	{
		auto [ver, mask] = q.front();
		q.pop();
		for (auto& i : graph[ver])
		{
			int nxt = mask;
			if (nxt & (1 << i))
			{
				nxt &= ~(1 << i);
			}
			else
			{
				nxt |= (1 << i);
			}
			if (visited[i][nxt] > visited[ver][mask] + 1)
			{
				visited[i][nxt] = visited[ver][mask] + 1;
				q.push(make_tuple(i, nxt));
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i < (1 << n); ++i)
	{
		int temp = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			temp = min(temp, visited[j][i]);
		}
		ans += temp;
	}
	cout << ans;
	return 0;
}
