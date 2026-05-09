#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<vector<ll>>v(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		for (ll j = 0; j < a; ++j)
		{
			ll b = 0;
			cin >> b;
			v[i].push_back(b);
		}
	}
	ll idx = 1;
	for (ll i = 1; i <= n && k; ++i)
	{
		ll a = 0, len = v[i].size();
		cin >> a;
		if (k > len * a)
		{
			k -= len * a;
			continue;
		}
		cout << v[i][(k - 1) % len];
		return 0;
	}
	return 0;
}
