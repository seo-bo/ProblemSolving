#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	vector<tp> p;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char a;
			cin >> a;
			if (a == '.' || a == '#')
			{
				v[i][j] = a;
				continue;
			}
			p.push_back(make_tuple(i, j, a - '0'));
			v[i][j] = '.';
		}
	}
	for (auto &[x, y, cnt] : p)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (abs(x - i) + abs(j - y) <= cnt)
				{
					v[i][j] = '.';
				}
			}
		}
	}
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			cout << j;
		}
		cout << '\n';
	}
	return 0;
}
