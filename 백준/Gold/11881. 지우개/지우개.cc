#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>cnt(100003), v(n);
	for (auto& i : v)
	{
		cin >> i;
		cnt[i]++;
	}
	for (int i = 1; i <= 100000; ++i)
	{
		cnt[i] = ((ll)cnt[i] * i + cnt[i - 1]) % MOD;
	}
	ll ans = 0;
	for (auto& i : v)
	{
		ans = (ans + (ll)i * cnt[i - 1] % MOD * (cnt[100000] - cnt[i] + MOD) % MOD) % MOD;
	}
	cout << ans;
	return 0;
}