#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto power = [&](ll base)
		{
			ll res = 1, exp = MOD - 2;
			while (exp)
			{
				if (exp & 1)
				{
					res = (res * base) % MOD;
				}
				base = (base * base) % MOD;
				exp >>= 1;
			}
			return res;
		};
	unordered_map<ll, ll>dp;
	ll n = 0;
	cin >> n;
	dp[n] = 1;
	priority_queue<ll>pq;
	pq.push(n);
	while (!pq.empty())
	{
		ll cur = pq.top();
		pq.pop();
		for (int i = 2; i <= 6; ++i)
		{
			if (cur % i == 0)
			{
				ll nxt = cur / i;
				if (dp.find(nxt) == dp.end())
				{
					pq.push(nxt);
				}
				dp[nxt] = (dp[nxt] + dp[cur] * power(5)) % MOD;
			}
		}
	}
	cout << dp[1];
	return 0;
}
