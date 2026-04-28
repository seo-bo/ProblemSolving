#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, d = 0;
	cin >> n >> d;
	d *= d;
	map<int, pii>mm;
	map<pii, int>rev;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		mm[i] = make_pair(a, b);
		rev[make_pair(a, b)] = i;
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
			{
				continue;
			}
			auto [ax, ay] = mm[i];
			auto [bx, by] = mm[j];
			ll co = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
			if (co <= d)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	vector<bool>visited(n + 1);
	queue<int>q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ((visited[i]) ? "Yes" : "No") << '\n';
	}
	return 0;
}
