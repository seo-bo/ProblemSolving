#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<char>> v(h, vector<char>(w)), res(h, vector<char>(w));
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			cin >> j;
		}
	}
	for (auto &i : res)
	{
		for (auto &j : i)
		{
			cin >> j;
		}
	}
	for (int a = 0; a < h; ++a)
	{
		for (int b = 0; b < w; ++b)
		{
			int f = 1;
			for (int i = 0; i < h && f; ++i)
			{
				for (int j = 0; j < w && f; ++j)
				{
					int nx = (i - a + h) % h, ny = (j - b + w) % w;
					f &= (v[nx][ny] == res[i][j]);
				}
			}
			if (f)
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
