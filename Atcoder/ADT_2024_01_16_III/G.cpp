#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	unordered_map<int, unordered_set<int>> s;
	unordered_map<int, unordered_map<int, int>> visited;
	unordered_map<int, int> score;
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		queue<int> q;
		q.push(a);
		visited[i][a] = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			s[cur].insert(i);
			if (cur % 2 == 0)
			{
				int nxt = cur / 2;
				if (visited[i].find(nxt) == visited[1].end() || visited[i][nxt] > visited[i][cur] + 1)
				{
					int co = visited[i][cur] + 1;
					if (visited.find(nxt) == visited.end())
					{
						score[nxt] += co;
					}
					else
					{
						score[nxt] += co - visited[i][nxt];
					}
					visited[i][nxt] = co;
					q.push(nxt);
				}
			}
			if (cur % 3 == 0)
			{
				int nxt = cur / 3;
				if (visited[i].find(nxt) == visited[i].end() || visited[i][nxt] > visited[i][cur] + 1)
				{
					int co = visited[i][cur] + 1;
					if (visited.find(nxt) == visited.end())
					{
						score[nxt] += co;
					}
					else
					{
						score[nxt] += co - visited[i][nxt];
					}
					visited[i][nxt] = co;
					q.push(nxt);
				}
			}
		}
	}
	int ans = INT_MAX;
	for (auto &[a, b] : s)
	{
		if (b.size() != n)
		{
			continue;
		}
		ans = min(ans, score[a]);
	}
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}
