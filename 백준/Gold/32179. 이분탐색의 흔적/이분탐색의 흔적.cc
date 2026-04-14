#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>v(n + 2);
	v[n + 1] = 101;
	int left = 1, right = n, mid = (left + right) / 2;
	cin >> v[mid];
	for (int i = 1; i < k; ++i)
	{
		int a = 0;
		cin >> a;
		if (a < v[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		mid = (left + right) / 2;
		v[mid] = a;
	}
	vector<ll>fact(101, 1);
	for (int i = 2; i <= 100; ++i)
	{
		fact[i] = fact[i - 1] * i % MOD;
	}
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
	ll ans = 1, cnt = 0, start = 1;
	for (int i = 1; i <= n + 1 && start <= 100; ++i)
	{
		if (!v[i])
		{
			cnt++;
		}
		else
		{
			ll p = v[i] - start;
			ans = ans * fact[p] % MOD * power(fact[cnt]) % MOD * power(fact[p - cnt]) % MOD;
			cnt = 0, start = v[i] + 1;
		}
	}
	cout << ans;
	return 0;
}