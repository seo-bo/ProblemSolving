#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MAX 1000000

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<bool>flag(MAX + 2, 1);
	for (ll i = 2; i <= MAX; ++i)
	{
		if (flag[i])
		{
			for (ll j = i * i; j <= MAX; j += i)
			{
				flag[j] = false;
			}
		}
	}
	vector<ll>prime;
	for (ll i = 2; i <= MAX; ++i)
	{
		if (flag[i])
		{
			prime.push_back(i);
		}
	}
	ll ans = 0, n = 0, len = prime.size();
	cin >> n;
	for (ll i = 0; prime[i] <= 1000; ++i)
	{
		for (ll j = i + 1; prime[j] <= 10000; ++j)
		{
			ll p = prime[i] * prime[i] * prime[j];
			if (p > n)
			{
				break;
			}
			ll it = upper_bound(prime.begin(), prime.end(), sqrtl((long double)n / p)) - prime.begin();
			ans += max(0LL, it - j - 1);
		}
	}
	cout << ans;
	return 0;
}
