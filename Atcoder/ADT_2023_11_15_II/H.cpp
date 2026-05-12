#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll> cost(n + 1);
	vector<vector<ll>> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			v[i].push_back(b);
		}
	}
	vector<ld> dp(m + 1, INT_MAX);
	dp[m] = 0;
	for (int i = m - 1; i >= 0; --i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ld temp = cost[j];
			int siz = v[j].size(), cnt = 0;
			for (auto &k : v[j])
			{
				cnt += (k == 0);
				int nxt = min(m, i + k);
				if (k)
				{
					temp += dp[nxt] / (ld)siz;
				}
			}
			dp[i] = min(dp[i], temp / ((ld)1 - (ld)cnt / siz));
		}
	}
	cout << fixed << setprecision(15) << dp[0];
	return 0;
}
