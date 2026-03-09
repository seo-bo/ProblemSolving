#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>>graph(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		vector<int>visited(n + 1, -1);
		auto bfs = [&](int start)
			{
				visited[start] = 0;
				queue<int>q;
				q.push(start);
				while (!q.empty())
				{
					int cur = q.front();
					q.pop();
					for (auto& i : graph[cur])
					{
						if (visited[i] == visited[cur])
						{
							return 0;
						}
						if (visited[i] == -1)
						{
							visited[i] = visited[cur] ^ 1;
							q.push(i);
						}
					}
				}
				return 1;
			};
		int flag = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (visited[i] == -1)
			{
				flag &= bfs(i);
			}
		}
		cout << ((flag) ? "possible\n" : "impossible\n");
	}
	return 0;
}