#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, q = 0;
	cin >> h >> w >> q;
	vector<vector<int>>v(h + 3, vector<int>(w + 3));
	vector<char>res(q + 1, 'A');
	for (int i = 1; i <= q; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b >> res[i];
		v[a][b] = i;
	}
	for (int i = h; i >= 1; --i)
	{
		for (int j = w; j >= 1; --j)
		{
			v[i][j] = max({ v[i + 1][j], v[i][j + 1], v[i][j] });
		}
	}
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cout << res[v[i][j]];
		}
		cout << '\n';
	}
	return 0;
}
