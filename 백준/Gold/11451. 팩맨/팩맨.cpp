#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int> tp;
typedef tuple<int, int, int, int, int> ttp;

int visited[51][51][51][51] = { 0, };
ttp parent[51][51][51][51];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<char>alpha = { 'N','S','W','E' };
	int T = 0;
	cin >> T;
	while (T--)
	{
		memset(visited, -1, sizeof(visited));
		int n = 0, m = 0;
		cin >> n >> m;
		for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < m; ++b)
			{
				for (int c = 0; c < n; ++c)
				{
					for (int d = 0; d < m; ++d)
					{
						parent[a][b][c][d] = make_tuple(-1, -1, -1, -1, -1);
					}
				}
			}
		}
		vector<vector<char>>v(n, vector<char>(m));
		int Ax = -1, Ay = -1, Bx = -1, By = -1;
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; ++j)
			{
				v[i][j] = str[j];
				if (v[i][j] == 'P')
				{
					if (Ax == -1)
					{
						Ax = i;
						Ay = j;
					}
					else
					{
						Bx = i;
						By = j;
					}
				}
			}
		}
		tp ok = make_tuple(-1, -1, -1, -1);
		auto bfs = [&]
			{
				visited[Ax][Ay][Bx][By] = 0;
				queue<tp>q;
				q.push(make_tuple(Ax, Ay, Bx, By));
				while (!q.empty())
				{
					auto [ax, ay, bx, by] = q.front();
					if (ax == bx && ay == by)
					{
						ok = make_tuple(ax, ay, bx, by);
						cout << visited[ax][ay][bx][by] << ' ';
						return true;
					}
					q.pop();
					for (int i = 0; i < 4; ++i)
					{
						int tx = (ax + dir[i][0] + n) % n;
						int ty = (ay + dir[i][1] + m) % m;
						if (v[tx][ty] == 'X')
						{
							tx = ax, ty = ay;
						}
						int px = (bx + dir[i][0] + n) % n;
						int py = (by + dir[i][1] + m) % m;
						if (v[px][py] == 'X')
						{
							px = bx, py = by;
						}
						if (v[px][py] == 'G' || v[tx][ty] == 'G')
						{
							continue;
						}
						if (visited[tx][ty][px][py] == -1 || visited[tx][ty][px][py] > visited[ax][ay][bx][by] + 1)
						{
							visited[tx][ty][px][py] = visited[ax][ay][bx][by] + 1;
							q.push(make_tuple(tx, ty, px, py));
							parent[tx][ty][px][py] = make_tuple(ax, ay, bx, by, i);
						}
					}
				}
				return false;
			};
		if (!bfs())
		{
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		string ans;
		while (1)
		{
			auto [ax, ay, bx, by] = ok;
			auto [aax, aay, bbx, bby, d] = parent[ax][ay][bx][by];
			if (aax == -1)
			{
				break;
			}
			ans += alpha[d];
			ok = make_tuple(aax, aay, bbx, bby);
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}