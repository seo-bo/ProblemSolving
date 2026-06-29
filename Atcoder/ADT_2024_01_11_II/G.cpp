#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[300001][2];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	ll x = 0, y = 0, z = 0;
	cin >> x >> y >> z;
	string str;
	cin >> str;
	int len = str.size();
	function<ll(int, int)> dfs = [&](int idx, int now)
		{
			if (idx == len)
			{
				return 0LL;
			}
			if (dp[idx][now] != -1)
			{
				return dp[idx][now];
			}
			ll res = LLONG_MAX / 8;
			char a = (now) ? 'A' : 'a';
			res = min({ res, dfs(idx + 1, now) + ((a == str[idx]) ? x : y), dfs(idx + 1,now ^ 1) + z + min(x,y) });
			return dp[idx][now] = res;
		};
	cout << dfs(0, 0);
	return 0;
}
