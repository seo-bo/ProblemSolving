#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<ll, ll> a, b;
	int n = 0;
	cin >> n;
	ll ans = 0;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		ans += a[v[i]] * (i - a[v[i]]);
		a[v[i]]++;
	}
	for (int i = n - 1; i >= 0; --i)
	{
		a[v[i]]--;
		ans -= b[v[i]] * (i - a[v[i]]);
		b[v[i]]++;
	}
	cout << ans;
	return 0;
}
