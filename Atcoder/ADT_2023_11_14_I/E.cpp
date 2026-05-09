#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	string base = "UDLR";
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<char>> v(h + 1, vector<char>(w + 1));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> v[i][j];
		}
	}
	int x = 1, y = 1;
	vector<vector<bool>> visited(h + 1, vector<bool>(w + 1));
	visited[1][1] = 1;
	while (1)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (base[i] == v[x][y])
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 1 && nx <= h && ny >= 1 && ny <= w)
				{
					if (visited[nx][ny])
					{
						cout << -1;
						return 0;
					}
					visited[nx][ny] = 1;
					x = nx, y = ny;
				}
				else
				{
					cout << x << ' ' << y;
					return 0;
				}
				break;
			}
		}
	}
	return 0;
}
