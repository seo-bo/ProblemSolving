#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		int len = str.size(), k = 0;
		cin >> k;
		vector<int>v(len);
		for (int i = 0; i < len; ++i)
		{
			if (i >= 2)
			{
				v[i] = (str[i - 2] == 'A' && str[i - 1] == 'B' && str[i] == 'C');
			}
			if (str[i] != 'A' && str[i] != 'B' && str[i] != 'C')
			{
				str[i] = 'D';
			}
		}
		vector<vector<vector<ll>>>dp(len + 1, vector<vector<ll>>(k + 1, vector<ll>(3, -1)));
		function<ll(int, int, int)> dfs = [&](int idx, int cnt, int t)
			{
				if (idx == len)
				{
					return (cnt == k) ? 0LL : LLONG_MAX / 8;
				}
				if (dp[idx][cnt][t] != -1)
				{
					return dp[idx][cnt][t];
				}
				ll res = LLONG_MAX / 8;
				for (char i = 'A'; i <= 'D'; ++i)
				{
					int co = cnt - v[idx], nxt = 0;
					if (i == 'A')
					{
						nxt = 1;
					}
					else if (i == 'B')
					{
						nxt = (t == 1) ? 2 : 0;
					}
					else if (i == 'C')
					{
						co += (t == 2);
						nxt = 0;
					}
					if (co >= 0 && co <= k)
					{
						res = min(res, dfs(idx + 1, co, nxt) + (str[idx] != i));
					}
				}
				return dp[idx][cnt][t] = res;
			};
		ll ans = dfs(0, 0, 0);
		cout << ((ans == LLONG_MAX / 8) ? -1 : ans) << '\n';
	}
	return 0;
}
