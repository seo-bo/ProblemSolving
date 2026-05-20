#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int H = 0, W = 0, N = 0, h = 0, w = 0;
	cin >> H >> W >> N >> h >> w;
	vector<vector<vector<int>>> prefix(H + 1, vector<vector<int>>(W + 1, vector<int>(N + 1)));
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			int a = 0;
			cin >> a;
			for (int k = 1; k <= N; ++k)
			{
				prefix[i][j][k] = prefix[i - 1][j][k] + prefix[i][j - 1][k] - prefix[i - 1][j - 1][k] + (a == k);
			}
		}
	}
	auto cal = [&](int sx, int sy, int f = 1)
	{
		int ex = sx + h - 1, ey = sy + w - 1;
		if (!f)
		{
			ex = H, ey = W;
		}
		map<int, int> mm;
		for (int i = 1; i <= N; ++i)
		{
			int res = prefix[ex][ey][i] - prefix[sx - 1][ey][i] - prefix[ex][sy - 1][i] + prefix[sx - 1][sy - 1][i];
			if (res)
			{
				mm[i] = res;
			}
		}
		return mm;
	};
	map<int, int> mm = cal(1, 1, 0);
	int base = mm.size();
	for (int x = 1; x + h - 1 <= H; ++x)
	{
		for (int y = 1; y + w - 1 <= W; ++y)
		{
			map<int, int> temp = cal(x, y);
			int res = base;
			for (auto &[a, b] : temp)
			{
				res -= (mm[a] == b);
			}
			cout << res << ' ';
		}
		cout << '\n';
	}
	return 0;
}
