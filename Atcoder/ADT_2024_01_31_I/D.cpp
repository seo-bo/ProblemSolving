#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii>A, B;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if ((i < 3 && j < 3) || (i >= 6 && j >= 6))
			{
				A.push_back(make_pair(i, j));
			}
			else if ((i < 4 && j < 4) || (i >= 5 && j >= 5))
			{
				B.push_back(make_pair(i, j));
			}
		}
	}
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto cal = [&](int x, int y)
		{
			for (auto& [d1, d2] : A)
			{
				int nx = x + d1, ny = y + d2;
				if (nx >= n || ny >= m || v[nx][ny] != '#')
				{
					return false;
				}
			}
			for (auto& [d1, d2] : B)
			{
				int nx = x + d1, ny = y + d2;
				if (nx >= n || ny >= m || v[nx][ny] != '.')
				{
					return false;
				}
			}
			return true;
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (cal(i, j))
			{
				cout << i + 1 << ' ' << j + 1 << '\n';
			}
		}
	}
	return 0;
}
