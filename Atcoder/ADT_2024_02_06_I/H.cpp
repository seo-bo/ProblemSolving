#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[5001];

/*
* 1 1
* 1 2 1
* 1 2 2 1
* 1 2 3 2 1
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1), prefix(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	function<ll(int)> dfs = [&](int idx)
		{
			if (idx >= n + 1)
			{
				return 0LL;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			ll res = dfs(idx + 1);
			for (int i = idx; i <= n; ++i)
			{
				int len = (i - idx + 1), hf = (len + 1) / 2;
				ll temp = prefix[hf] * 2;
				if (len % 2)
				{
					temp -= v[hf];
				}
				res = max(res, dfs(i + 2) + temp);
			}
			return dp[idx] = res;
		};
	cout << dfs(2);
	return 0;
}
