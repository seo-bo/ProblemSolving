#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int prefix[301][301][301];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int H = 0, W = 0, n = 0, h = 0, w = 0;
	cin >> H >> W >> n >> h >> w;
	--h, --w;
	vector<int>cnt(n + 1);
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			int a = 0;
			cin >> a;
			cnt[a]++;
			for (int k = 1; k <= n; ++k)
			{
				prefix[i][j][k] = prefix[i - 1][j][k] + prefix[i][j - 1][k] - prefix[i - 1][j - 1][k] + (a == k);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		res += min(1, cnt[i]);
	}
	auto cal = [&](int sx, int sy, int ex, int ey, int k)
		{
			return prefix[ex][ey][k] - prefix[sx - 1][ey][k] - prefix[ex][sy - 1][k] + prefix[sx - 1][sy - 1][k];
		};
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			int nx = i + h, ny = j + w;
			if (nx >= 1 && nx <= H && ny >= 1 && ny <= W)
			{
				int temp = res;
				for (int k = 1; k <= n; ++k)
				{
					if (!cnt[k])
					{
						continue;
					}
					if (cnt[k] == cal(i, j, nx, ny, k))
					{
						temp--;
					}
				}
				cout << temp << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
