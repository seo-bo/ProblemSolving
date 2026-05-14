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
	vector<vector<char>> v(h, vector<char>(w));
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			cin >> j;
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j + 1 < w;)
		{
			if (v[i][j] == v[i][j + 1] && v[i][j] == 'T')
			{
				v[i][j] = 'P', v[i][j + 1] = 'C';
				j += 2;
				continue;
			}
			++j;
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
