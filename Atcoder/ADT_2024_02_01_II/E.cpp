#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>v(k + 1);
	for (int i = 1; i <= k; ++i)
	{
		cin >> v[i];
	}
	if (k % 2 == 0)
	{
		ll ans = 0;
		for (int i = 2; i <= k; i += 2)
		{
			ans += v[i] - v[i - 1];
		}
		cout << ans;
		return 0;
	}
	vector<ll>prefix(k + 5), suffix(k + 5);
	for (int i = 2; i <= k; i += 2)
	{
		prefix[i] = prefix[i - 2] + v[i] - v[i - 1];
	}
	for (int i = k - 1; i >= 2; i -= 2)
	{
		suffix[i] = suffix[i + 2] + v[i + 1] - v[i];
	}
	ll ans = LLONG_MAX;
	for (int i = 1; i <= k; i += 2)
	{
		ans = min(ans, prefix[i - 1] + suffix[i + 1]);
	}
	cout << ans;
	return 0;
}
