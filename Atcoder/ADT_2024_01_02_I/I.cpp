#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[26][5001];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	string str;
	cin >> str;
	vector<int> alpha(26);
	for (auto &i : str)
	{
		alpha[i - 'a']++;
	}
	int len = str.size();
	vector<ll> fact(len + 1, 1), inv(len + 1, 1);
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
	for (ll i = 2; i <= len; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = power(fact[i]);
	}
	function<ll(ll, ll)> dfs = [&](ll idx, ll s)
	{
		if (idx == 26)
		{
			return min(s, 1LL);
		}
		if (dp[idx][s] != -1)
		{
			return dp[idx][s];
		}
		ll res = 0;
		for (int i = 0; i <= alpha[idx]; ++i)
		{
			ll nxt = s + i;
			res = (res + (dfs(idx + 1, nxt) % MOD * fact[nxt] % MOD * inv[s] % MOD * inv[nxt - s] % MOD)) % MOD;
		}
		return dp[idx][s] = res;
	};
	cout << dfs(0, 0);
	return 0;
}
