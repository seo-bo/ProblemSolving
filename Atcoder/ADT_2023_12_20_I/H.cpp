#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<ll> dp(n + 1);
	dp[1] = 1;
	ll sum = 1;
	for (int i = 1; i <= k; ++i)
	{
		vector<ll> temp(n + 1);
		ll nxt = 0;
		for (int j = 1; j <= n; ++j)
		{
			temp[j] = (sum - dp[j] + MOD) % MOD;
			for (auto &p : graph[j])
			{
				temp[j] = (temp[j] - dp[p] + MOD) % MOD;
			}
			nxt = (nxt + temp[j]) % MOD;
		}
		dp = move(temp);
		sum = nxt;
	}
	cout << dp[1];
	return 0;
}
