#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	vector<tp>pos;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			if ('0' <= v[i][j] && v[i][j] <= '9')
			{
				pos.push_back(make_tuple(i, j, v[i][j] - '0'));
			}
		}
	}
	for (auto& [x, y, len] : pos)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (abs(i - x) + abs(j - y) <= len)
				{
					v[i][j] = '.';
				}
			}
		}
	}
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << j;
		}
		cout << '\n';
	}
	return 0;
}
