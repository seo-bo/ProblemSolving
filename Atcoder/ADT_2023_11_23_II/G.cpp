#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, n = 0;
	cin >> a >> n;
	vector<int> visited(n * 10 + 1, INT_MAX);
	visited[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur > 10)
		{
			int len = 1;
			while (cur / len)
			{
				len *= 10;
			}
			len /= 10;
			if (cur % len >= len / 10)
			{
				int p = cur / len;
				int nxt = (cur - p * len) * 10 + p;
				if (visited[nxt] > visited[cur] + 1)
				{
					visited[nxt] = visited[cur] + 1;
					q.push(nxt);
				}
			}
		}
		if (cur % a == 0)
		{
			int nxt = cur / a;
			if (visited[nxt] > visited[cur] + 1)
			{
				visited[nxt] = visited[cur] + 1;
				q.push(nxt);
			}
		}
	}
	cout << ((visited[1] == INT_MAX) ? -1 : visited[1]);
	return 0;
}
