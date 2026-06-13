#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int v[501][501], prefix[501][501];
int cnt[502 * 502];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, k = 0;
	cin >> h >> w >> k;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			char a;
			cin >> a;
			v[i][j] = a - '0';
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + v[i][j];
		}
	}
	auto query = [&](int sx, int sy, int ex, int ey)
		{
			return prefix[ex][ey] - prefix[sx - 1][ey] - prefix[ex][sy - 1] + prefix[sx - 1][sy - 1];
		};
	ll ans = 0;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = i; j <= h; ++j)
		{
			cnt[0] = 1;
			ll pre = 0;
			for (int z = 1; z <= w; ++z)
			{
				pre = pre + query(i, z, j, z);
				if (pre - k >= 0)
				{
					ans += cnt[pre - k];
				}
				cnt[pre]++;
			}
			memset(cnt, 0, sizeof(cnt));
		}
	}
	cout << ans;
	return 0;
}
