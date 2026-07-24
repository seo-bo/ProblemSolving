#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char a;
			cin >> a;
			v[i][j] = (a == '#');
		}
	}
	vector<vector<int>>dir = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<vector<int>>>visited(n + 1, vector<vector<int>>(m + 1, vector<int>(5)));
	visited[2][2][0] = 1;
	queue<tp>q;
	q.push(make_tuple(2, 2, 0));
	while (!q.empty())
	{
		auto [x, y, d] = q.front();
		q.pop();
		int flag = 0;
		if (d)
		{
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			if (v[nx][ny])
			{
				flag = 1;
			}
			else
			{
				if (!visited[nx][ny][d])
				{
					visited[nx][ny][d] = 1;
					q.push(make_tuple(nx, ny, d));
				}
			}
		}
		if (!d || flag)
		{
			for (int i = 1; i <= 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (!v[nx][ny] && !visited[nx][ny][i])
				{
					visited[nx][ny][i] = 1;
					q.push(make_tuple(nx, ny, i));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int temp = 0;
			for (int k = 0; k <= 4; ++k)
			{
				temp |= visited[i][j][k];
			}
			ans += temp;
		}
	}
	cout << ans;
	return 0;
}
