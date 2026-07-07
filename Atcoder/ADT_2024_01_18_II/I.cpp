#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int dp[16][1 << 16][27];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (int i = 0; i < n; ++i)
	{
		auto& [a, b] = v[i];
		string str;
		cin >> str;
		a = str.front() - 'a' + 1, b = str.back() - 'a' + 1;
	}
	function<int(int, int, int)> dfs = [&](int idx, int mask, int pre)
		{
			if (idx == n)
			{
				return 0;
			}
			if (dp[idx][mask][pre] != -1)
			{
				return dp[idx][mask][pre];
			}
			int res = 0;
			for (int i = 0; i < n; ++i)
			{
				if (mask & (1 << i))
				{
					continue;
				}
				auto& [a, b] = v[i];
				if (pre != a)
				{
					continue;
				}
				res |= !dfs(idx + 1, mask | (1 << i), b);
			}
			return dp[idx][mask][pre] = res;
		};
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans |= !dfs(1, 1 << i, v[i].second);
	}
	cout << ((ans) ? "First" : "Second");
	return 0;
}
