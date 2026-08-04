#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0, ans = LLONG_MAX;
	cin >> n >> x;
	ll mini = LLONG_MAX, sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		sum += a + b;
		mini = min(mini, b);
		ans = min(ans, sum + (x - i) * mini);
	}
	cout << ans;
	return 0;
}
