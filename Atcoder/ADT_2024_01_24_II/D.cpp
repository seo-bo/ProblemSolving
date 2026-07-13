#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, s = 0, m = 0, l = 0;
	cin >> n >> s >> m >> l;
	int ans = INT_MAX;
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			for (int k = 0; k <= 100; ++k)
			{
				if (6 * i + 8 * j + 12 * k >= n)
				{
					ans = min(ans, s * i + m * j + l * k);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
