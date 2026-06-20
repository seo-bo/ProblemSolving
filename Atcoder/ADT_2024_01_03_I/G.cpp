#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int m = 0;
	cin >> m;
	vector<vector<int>>graph(10);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	string base(10, 'x'), res = "!12345678x";
	base[0] = '!';
	for (int i = 1; i <= 8; ++i)
	{
		int a = 0;
		cin >> a;
		base[a] = char(i + '0');
	}
	unordered_map<string, int>visited;
	visited[base] = 0;
	queue<string>q;
	q.push(base);
	while (!q.empty())
	{
		string cur = q.front();
		q.pop();
		if (cur == res)
		{
			cout << visited[cur];
			return 0;
		}
		string nxt = cur;
		int idx = cur.find('x');
		for (auto& i : graph[idx])
		{
			swap(nxt[idx], nxt[i]);
			if (visited.find(nxt) == visited.end() || visited[nxt] > visited[cur] + 1)
			{
				visited[nxt] = visited[cur] + 1;
				q.push(nxt);
			}
			swap(nxt[idx], nxt[i]);
		}
	}
	cout << -1;
	return 0;
}
