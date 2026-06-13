#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int>tp;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<char>>v(h + 1, vector<char>(w + 1));
	vector<vector<int>>dir = { {0,-1},{0,1},{-1,0},{1,0} };
	string base = "<>^v";
	queue<tp>nq;
	vector<vector<vector<int>>>ban(h + 1, vector<vector<int>>(w + 1, vector<int>(4)));
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 'S')
			{
				sx = i, sy = j;
			}
			if (v[i][j] == 'G')
			{
				ex = i, ey = j;
			}
			int idx = -1;
			for (int k = 0; k < 4; ++k)
			{
				if (base[k] == v[i][j])
				{
					idx = k;
					break;
				}
			}
			if (idx == -1)
			{
				continue;
			}
			nq.push(make_tuple(i, j, idx));
			ban[i][j][idx] = 1;
		}
	}
	while (!nq.empty())
	{
		auto [x, y, d] = nq.front();
		nq.pop();
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && !ban[nx][ny][d] && v[nx][ny] == '.')
		{
			nq.push(make_tuple(nx, ny, d));
			ban[nx][ny][d] = 1;
		}
	}
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			int flag = 0;
			for (int k = 0; k < 4; ++k)
			{
				flag |= ban[i][j][k];
			}
			if (flag)
			{
				v[i][j] = '#';
			}
		}
	}
	queue<pii>q;
	q.push(make_pair(sx, sy));
	vector<vector<int>>visited(h + 1, vector<int>(w + 1, INT_MAX));
	visited[sx][sy] = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && v[nx][ny] != '#')
			{
				if (visited[nx][ny] > visited[x][y] + 1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << ((visited[ex][ey] == INT_MAX) ? -1 : visited[ex][ey]);
	return 0;
}
