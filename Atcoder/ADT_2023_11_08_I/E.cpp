#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll> v(n + 1), prefix(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	ll k = 0;
	cin >> k;
	ll ans = k / prefix[n] * n;
	k %= prefix[n];
	for (int i = 1; i <= n; ++i)
	{
		if (prefix[i] > k)
		{
			cout << ans + i;
			return 0;
		}
	}
	return 0;
}
