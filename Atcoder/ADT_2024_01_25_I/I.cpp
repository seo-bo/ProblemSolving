#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].second;
	}
	sort(v.begin(), v.end());
	vector<ll>dp(5001);
	dp[0] = 1;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		auto [a, b] = v[i];
		for (int j = 0; j + b <= a; ++j)
		{
			ans = (ans + dp[j]) % MOD;
		}
		for (int j = 5000 - b; j >= 0; --j)
		{
			dp[j + b] = (dp[j + b] + dp[j]) % MOD;
		}
	}
	cout << ans;
	return 0;
}
