#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<pii>>graph(n + 1);
	int st = 0, ed = 0;
	cin >> st >> ed;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	queue<tp>q;
	q.push(make_tuple(0, 0, st));
	vector<vector<int>>visited(n + 1, vector<int>(n + 1, INT_MAX));
	visited[st][0] = 0;
	while (!q.empty())
	{
		auto [cost, cnt, ver] = q.front();
		q.pop();
		if (cnt == n)
		{
			continue;
		}
		for (auto& [nv, nc] : graph[ver])
		{
			if (visited[nv][cnt + 1] > visited[ver][cnt] + nc)
			{
				visited[nv][cnt + 1] = visited[ver][cnt] + nc;
				q.push(make_tuple(visited[nv][cnt + 1], cnt + 1, nv));
			}
		}
	}
	auto check = [&](int pivot)
		{
			int ans = INT_MAX;
			for (int i = 0; i <= n; ++i)
			{
				if (visited[ed][i] == INT_MAX)
				{
					continue;
				}
				ans = min(ans, visited[ed][i] + i * pivot);
			}
			return ans;
		};
	int res = 0;
	for (int i = 0; i <= k; ++i)
	{
		int temp = 0;
		if (i)
		{
			cin >> temp;
		}
		res += temp;
		cout << check(res) << '\n';
	}
	return 0;
}