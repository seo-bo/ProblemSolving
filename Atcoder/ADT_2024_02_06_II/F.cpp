#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>prefix(n + 1), p(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		prefix[i] = prefix[i - 1] + a;
		p[i] = p[i - 1] + a * i;
	}
	ll ans = LLONG_MIN;
	for (ll i = 1; i + m - 1 <= n; ++i)
	{
		ll right = i + m - 1, co = p[right] - p[i - 1] - (i - 1) * (prefix[right] - prefix[i - 1]);
		ans = max(ans, co);
	}
	cout << ans;
	return 0;
}
