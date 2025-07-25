#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		sum += temp;
	}
	ll ans = 1, pivot = k - sum;
	for (ll i = pivot + 1; i <= pivot + n; ++i)
	{
		ans = (ans * i) % MOD;
	}
	cout << ans;
	return 0;
}