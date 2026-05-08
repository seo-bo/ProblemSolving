#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, n = 0;
	cin >> h >> w >> n;
	int sx = 0, sy = 0, ex = 0, ey = 0;
	cin >> sx >> sy >> ex >> ey;
	map<int, set<int>> x, y;
	set<pll> pos = {{sx, sy}, {ex, ey}}, ban;
	vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		x[a].insert(b);
		y[b].insert(a);
		ban.insert(make_pair(a, b));
		pos.erase(make_pair(a, b));
		for (int j = 0; j < 4; ++j)
		{
			int nx = a + dir[j][0];
			int ny = b + dir[j][1];
			if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && ban.find(make_pair(nx, ny)) == ban.end())
			{
				pos.insert(make_pair(nx, ny));
			}
		}
	}
	vector<pll> ver(pos.begin(), pos.end());
	int start = -1, end = -1, len = ver.size();
	vector<vector<int>> graph(len + 1);
	for (int i = 0; i < len; ++i)
	{
		if (make_pair(sx, sy) == ver[i])
		{
			start = i;
		}
		if (make_pair(ex, ey) == ver[i])
		{
			end = i;
		}
		auto [xx, yy] = ver[i];
		if (x.find(xx) != x.end())
		{
			auto it = x[xx].upper_bound(yy);
			if (it != x[xx].end())
			{
				if (yy < *it)
				{
					int idx = lower_bound(ver.begin(), ver.end(), make_pair(xx, *it - 1)) - ver.begin();
					if (i != idx)
					{
						graph[i].push_back(idx);
					}
				}
			}
			if (it != x[xx].begin())
			{
				it = prev(it);
				if (*it < yy)
				{
					int idx = lower_bound(ver.begin(), ver.end(), make_pair(xx, *it + 1)) - ver.begin();
					if (i != idx)
					{
						graph[i].push_back(idx);
					}
				}
			}
		}
		if (y.find(yy) != y.end())
		{
			auto it = y[yy].upper_bound(xx);
			if (it != y[yy].end())
			{
				if (xx < *it)
				{
					int idx = lower_bound(ver.begin(), ver.end(), make_pair(*it - 1, yy)) - ver.begin();
					if (i != idx)
					{
						graph[i].push_back(idx);
					}
				}
			}
			if (it != y[yy].begin())
			{
				it = prev(it);
				if (*it < xx)
				{
					int idx = lower_bound(ver.begin(), ver.end(), make_pair(*it + 1, yy)) - ver.begin();
					if (i != idx)
					{
						graph[i].push_back(idx);
					}
				}
			}
		}
	}
	vector<ll> dist(len + 1, LLONG_MAX);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto &i : graph[cur])
		{
			if (dist[i] > dist[cur] + 1)
			{
				dist[i] = dist[cur] + 1;
				q.push(i);
			}
		}
	}
	cout << ((dist[end] == LLONG_MAX) ? -1 : dist[end]);
	return 0;
}
