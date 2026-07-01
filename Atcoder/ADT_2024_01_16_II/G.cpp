#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int lim = 1e6;
	vector<bool> flag(lim + 3, true);
	for (ll i = 2; i <= lim; ++i)
	{
		if (flag[i])
		{
			for (ll j = i * i; j <= lim; j += i)
			{
				flag[j] = false;
			}
		}
	}
	vector<ll> prime;
	for (int i = 2; i <= lim; ++i)
	{
		if (flag[i])
		{
			prime.push_back(i);
		}
	}
	int len = prime.size();
	ll n = 0, ans = 0;
	cin >> n;
	for (ll i = 0; i < len; ++i)
	{
		__int128 pivot = prime[i] * prime[i] * prime[i];
		if (pivot >= n)
		{
			break;
		}
		for (ll j = 0; j < i; ++j)
		{
			__int128 a = pivot * prime[j];
			if (a > n)
			{
				break;
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}
