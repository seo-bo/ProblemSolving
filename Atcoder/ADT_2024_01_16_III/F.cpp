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
	string base = "RLUD";
	vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
	vector<vector<char>> v(n, vector<char>(m));
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			cin >> j;
		}
	}
	queue<pii> q;
	vector<vector<int>> visited(n, vector<int>(m));
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		int d = -1;
		for (int i = 0; i < 4; ++i)
		{
			if (v[x][y] == base[i])
			{
				d = i;
				break;
			}
		}
		int nx = x + dir[d][0], ny = y + dir[d][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (visited[nx][ny])
			{
				cout << -1;
				return 0;
			}
			visited[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			continue;
		}
		cout << x + 1 << ' ' << y + 1 << '\n';
		return 0;
	}
	return 0;
}
