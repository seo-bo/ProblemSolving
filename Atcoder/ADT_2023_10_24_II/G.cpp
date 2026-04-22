#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n1 = 0, n2 = 0, m = 0;
	cin >> n1 >> n2 >> m;
	vector<vector<int>>graph(n1 + n2 + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>visited(n1 + n2 + 1, INT_MAX);
	auto bfs = [&](int start, int end)
		{
			queue<int>q;
			q.push(start);
			visited[start] = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto& i : graph[cur])
				{
					if (visited[i] > visited[cur] + 1)
					{
						visited[i] = visited[cur] + 1;
						q.push(i);
					}
				}
			}
			int ans = 0;
			if (start > end)
			{
				swap(start, end);
			}
			for (int i = start; i <= end; ++i)
			{
				ans = max(ans, visited[i]);
			}
			return ans;
		};
	cout << bfs(1, n1) + bfs(n1 + n2, n1 + 1) + 1;
	return 0;
}
