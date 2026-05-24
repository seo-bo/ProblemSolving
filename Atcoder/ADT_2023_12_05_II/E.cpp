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
	vector<vector<char>> v(h + 1, vector<char>(w + 1));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> v[i][j];
		}
	}
	int n = min(h, w);
	auto cal = [&](int d)
	{
		int p = 0;
		for (int i = 1; i <= h; ++i)
		{
			for (int j = 1; j <= w; ++j)
			{
				if (v[i][j] == '.')
				{
					continue;
				}
				int flag = 1;
				for (int k = 1; k <= d; ++k)
				{
					int xa = i + k, xb = i - k;
					int ya = j + k, yb = j - k;
					for (auto &t : {xa, xb})
					{
						for (auto &z : {ya, yb})
						{
							if (!(t >= 1 && t <= h && z >= 1 && z <= w) || v[t][z] != '#')
							{
								flag = 0;
								break;
							}
						}
					}
				}
				p += flag;
			}
		}
		return p;
	};
	for (int i = 1; i <= n; ++i)
	{
		cout << cal(i) - cal(i + 1) << ' ';
	}
	return 0;
}
