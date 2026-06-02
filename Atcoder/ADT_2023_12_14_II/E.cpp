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
	vector<ll> A(n + 1), B(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		A[i] += A[i - 1] + a;
		B[i] += B[i - 1] + a * i;
	}
	ll ans = LLONG_MIN;
	for (int i = m, j = 0; i <= n; ++i, ++j)
	{
		ll co = (A[i] - A[i - m]) * j;
		ans = max(ans, B[i] - B[i - m] - co);
	}
	cout << ans;
	return 0;
}
