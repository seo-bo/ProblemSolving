#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == 'S')
			{
				sx = i, sy = j;
			}
			if (v[i][j] == 'F')
			{
				ex = i, ey = j;
			}
		}
	}
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 'g')
			{
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m)
					{
						if (v[nx][ny] != '.')
						{
							continue;
						}
						v[nx][ny] = '?';
					}
				}
			}
		}
	}
	vector<vector<vector<int>>>dist(n, vector<vector<int>>(m, vector<int>(n * m + 1, INT_MAX)));
	dist[sx][sy][0] = 0;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(make_tuple(dist[sx][sy][0], 0, sx, sy));
	while (!pq.empty())
	{
		auto [co, cnt, x, y] = pq.top();
		pq.pop();
		if (dist[x][y][cnt] < co)
		{
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				int ncnt = cnt + (v[nx][ny] == 'g');
				if (ncnt == n * m)
				{
					continue;
				}
				int nco = (v[nx][ny] == '?');
				if (dist[nx][ny][ncnt] > dist[x][y][cnt] + nco)
				{
					dist[nx][ny][ncnt] = dist[x][y][cnt] + nco;
					pq.push(make_tuple(dist[nx][ny][ncnt], ncnt, nx, ny));
				}
			}
		}
	}
	for (int i = 0; i <= n * m; ++i)
	{
		if (dist[ex][ey][i] != INT_MAX)
		{
			cout << i << ' ' << dist[ex][ey][i];
			return 0;
		}
	}
	return 0;
}