#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, T = 0;
	cin >> n >> T;
	vector<vector<pii>>graph(n + 1);
	for (int i = 1; i <= n - 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	auto bfs = [&](int start)
		{
			vector<int>cnt(n + 1, INT_MAX), visited(n + 1, INT_MAX);
			visited[start] = 0, cnt[start] = 0;
			queue<int>q;
			q.push(start);
			int pivot = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto& [a, b] : graph[cur])
				{
					if (cnt[a] > cnt[cur] + 1)
					{
						visited[a] = visited[cur] + b, cnt[a] = cnt[cur] + 1;
						pivot = max(pivot, cnt[a]);
						q.push(a);
					}
				}
			}
			int res = -1, p = INT_MAX;
			for (int i = 1; i <= n; ++i)
			{
				if (cnt[i] == pivot && visited[i] < p)
				{
					res = i, p = visited[i];
				}
			}
			return make_pair(res, p);
		};
	cout << (bfs(bfs(1).first).second + T - 1) / T;
	return 0;
}