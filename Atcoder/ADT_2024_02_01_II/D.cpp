#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int r = 0, c = 0;
	cin >> r >> c;
	vector<vector<int>>v(16, vector<int>(16, -1));
	for (int i = 1, p = 1; i <= 15; ++i, p ^= 1)
	{
		for (int j = 1; j <= 15; ++j)
		{
			if (v[i][j] != -1)
			{
				continue;
			}
			v[i][j] = p;
			v[j][i] = p;
			v[15 - i + 1][j] = p;
			v[j][15 - i + 1] = p;
		}
	}
	cout << ((v[r][c] == 1) ? "black" : "white");
	return 0;
}
