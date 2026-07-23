#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int, int>tp;

ll visited[2001][2001][2][2];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<ll>row(h + 1), col(w + 1);
	for (int i = 1; i <= h; ++i)
	{
		cin >> row[i];
	}
	for (int i = 1; i <= w; ++i)
	{
		cin >> col[i];
	}
	vector<vector<int>>v(h + 1, vector<int>(w + 1));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			char p;
			cin >> p;
			v[i][j] = p - '0';
		}
	}
	auto cal = [&](int p)
		{
			for (int i = 1; i <= h; ++i)
			{
				for (int j = 1; j <= w; ++j)
				{
					for (int a = 0; a <= 1; ++a)
					{
						for (int b = 0; b <= 1; ++b)
						{
							visited[i][j][a][b] = LLONG_MAX;
						}
					}
				}
			}
			int inv = p ^ 1;
			queue<tp>q;
			if (v[1][1] == inv) // 현재 x , 현재 y, 현재 행을 반전시켰나, 현재 열을 반전시켰나
			{
				visited[1][1][1][0] = row[1], visited[1][1][0][1] = col[1];
				q.push(make_tuple(1, 1, 1, 0)), q.push(make_tuple(1, 1, 0, 1));
			}
			else
			{
				visited[1][1][0][0] = 0, visited[1][1][1][1] = row[1] + col[1];
				q.push(make_tuple(1, 1, 0, 0)), q.push(make_tuple(1, 1, 1, 1));
			}
			vector<vector<int>>dir = { {0,1},{1,0} };
			while (!q.empty())
			{
				auto [x, y, r, c] = q.front();
				q.pop();
				for (int i = 0; i < 2; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 1 && nx <= h && ny >= 1 && ny <= w)
					{
						int nr = 0, nc = 0;
						ll plus = 0;
						if (nx != x) // 밑으로 간거
						{
							nc = c;
							int nxt = v[nx][ny] ^ nc;
							if (nxt == inv) // 막혀있음, 이러면 밑의 행을 반전시키기
							{
								nr = 1, plus = row[nx];
							}
						}
						else // 오른쪽으로 간거
						{
							nr = r;
							int nxt = v[nx][ny] ^ nr;
							if (nxt == inv) // 막혀있음, 이러면 오른쪽 열을 반전시키기
							{
								nc = 1, plus = col[ny];
							}
						}
						if (visited[nx][ny][nr][nc] > visited[x][y][r][c] + plus)
						{
							visited[nx][ny][nr][nc] = visited[x][y][r][c] + plus;
							q.push(make_tuple(nx, ny, nr, nc));
						}
					}
				}
			}
			ll ans = LLONG_MAX;
			for (int i = 0; i <= 1; ++i)
			{
				for (int j = 0; j <= 1; ++j)
				{
					ans = min(ans, visited[h][w][i][j]);
				}
			}
			return ans;
		};
	cout << min(cal(0), cal(1));
	return 0;
}
