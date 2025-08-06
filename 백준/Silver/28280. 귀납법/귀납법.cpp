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
		int n = 0;
		cin >> n;
		int pivot = 0;
		for (int i = 0; pivot < n; ++i)
		{
			pivot = (1 << i);
		}
		auto bfs = [&]
			{
				vector<int>visited(n + 105, INT_MAX);
				queue<int>q;
				visited[n] = 0;
				q.push(n);
				while (!q.empty())
				{
					int cur = q.front();
					q.pop();
					if (cur == 1)
					{
						cout << visited[1] << '\n';
						return;
					}
					if (cur % 2 == 0 && visited[cur / 2] > visited[cur] + 1)
					{
						visited[cur / 2] = visited[cur] + 1;
						q.push(cur / 2);
					}
					if (cur + 1 <= n + 100 && visited[cur + 1] > visited[cur] + 1)
					{
						visited[cur + 1] = visited[cur] + 1;
						q.push(cur + 1);
					}
				}
				cout << "Wrong proof!\n";
			};
		bfs();
	}
	return 0;
}