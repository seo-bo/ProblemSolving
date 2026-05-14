#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>> v(6, vector<int>(6));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	auto cal = [&]
	{
		int cnt = 0;
		vector<vector<bool>> visited(6, vector<bool>(6));
		for (int i = 1; i <= 4; ++i)
		{
			for (int j = 1; j <= 4; ++j)
			{
				if (!visited[i][j] && v[i][j])
				{
					cnt++;
					queue<pii> q;
					visited[i][j] = true;
					q.push(make_pair(i, j));
					while (!q.empty())
					{
						auto [x, y] = q.front();
						q.pop();
						for (int k = 0; k < 4; ++k)
						{
							int nx = x + dir[k][0];
							int ny = y + dir[k][1];
							if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4 && v[nx][ny] && !visited[nx][ny])
							{
								visited[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
		queue<pii> q;
		visited[0][0] = true;
		q.push(make_pair(0, 0));
		while (!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			for (int k = 0; k < 4; ++k)
			{
				int nx = x + dir[k][0];
				int ny = y + dir[k][1];
				if (nx >= 0 && nx <= 5 && ny >= 0 && ny <= 5 && !v[nx][ny] && !visited[nx][ny])
				{
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
		int flag = (cnt == 1);
		for (int i = 1; i <= 4; ++i)
		{
			for (int j = 1; j <= 4; ++j)
			{
				flag &= (visited[i][j]);
			}
		}
		return flag;
	};
	int ans = 0;
	function<void(int, int)> dfs = [&](int x, int y)
	{
		if (x == 5)
		{
			if (cal())
			{
				ans++;
			}
			return;
		}
		int ny = (y == 4) ? 1 : y + 1, nx = (ny == 1) ? x + 1 : x;
		dfs(nx, ny);
		if (!v[x][y])
		{
			v[x][y] = 1;
			dfs(nx, ny);
			v[x][y] = 0;
		}
	};
	dfs(1, 1);
	cout << ans;
	return 0;
}
