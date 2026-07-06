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
	vector<vector<ll>> v(h, vector<ll>(w));
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			cin >> j;
		}
	}
	for (int a = 0; a < h; ++a)
	{
		for (int b = a + 1; b < h; ++b)
		{
			for (int c = 0; c < w; ++c)
			{
				for (int d = c + 1; d < w; ++d)
				{
					if (v[a][c] + v[b][d] > v[b][c] + v[a][d])
					{
						cout << "No";
						return 0;
					}
				}
			}
		}
	}
	cout << "Yes";
	return 0;
}
