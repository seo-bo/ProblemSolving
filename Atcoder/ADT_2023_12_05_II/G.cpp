#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pii> v;
	for (int i = -n; i <= n; ++i)
	{
		for (int j = -n; j <= n; ++j)
		{
			if (i * i + j * j == m)
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
	queue<pii> q;
	q.push(make_pair(1, 1));
	dist[1][1] = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (auto &[a, b] : v)
		{
			int nx = x + a, ny = y + b;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (dist[nx][ny] > dist[x][y] + 1)
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << ((dist[i][j] == INT_MAX) ? -1 : dist[i][j]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
