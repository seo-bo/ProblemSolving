#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int cnt[100001];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		cnt[a]++;
	}
	ll t = 0, ans = 0;
	for (int i = 1; i <= 100000; ++i)
	{
		t = (t + (ll)i * cnt[i]) % MOD;
	}
	for (int i = 1; i <= 100000; ++i)
	{
		ll a = cnt[i];
		cnt[i] = ((ll)cnt[i] * i + cnt[i - 1]) % MOD;
		if (a)
		{
			ans = (ans + (ll)i * a % MOD * cnt[i - 1] % MOD * (t - cnt[i] + MOD) % MOD) % MOD;
		}
	}
	cout << ans;
	return 0;
}