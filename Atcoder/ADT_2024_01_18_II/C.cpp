#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int s = 0, t = 0;
	cin >> s >> t;
	int ans = 0;
	function<void(int, int, int)> dfs = [&](int sum, int mul, int depth)
		{
			if (depth == 3)
			{
				ans += (sum <= s && mul <= t);
				return;
			}
			for (int i = 0; i <= 100; ++i)
			{
				dfs(sum + i, mul * i, depth + 1);
			}
		};
	dfs(0, 1, 0);
	cout << ans;
	return 0;
}
