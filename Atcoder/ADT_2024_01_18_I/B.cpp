#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int x = 0, y = 0, n = 0;
	cin >> x >> y >> n;
	int ans = INT_MAX;
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			if (i + 3 * j == n)
			{
				ans = min(ans, i * x + y * j);
			}
		}
	}
	cout << ans;
	return 0;
}
