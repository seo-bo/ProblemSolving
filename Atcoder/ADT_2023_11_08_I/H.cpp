#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll> x(m);
	map<ll, ll> even, odd;
	even[0] = 1;
	ll pre = 0;
	for (ll i = 0; i < n - 1; ++i)
	{
		ll a = 0;
		cin >> a;
		pre = a - pre;
		if (i % 2)
		{
			even[pre]++;
		}
		else
		{
			odd[pre]++;
		}
	}
	for (auto &i : x)
	{
		cin >> i;
	}
	map<ll, ll> ans;
	for (auto &[a, b] : even)
	{
		for (auto &i : x)
		{
			ans[i - a] += b;
		}
	}
	for (auto &[a, b] : odd)
	{
		for (auto &i : x)
		{
			ans[a - i] += b;
		}
	}
	ll res = 0;
	for (auto &[a, b] : ans)
	{
		res = max(res, b);
	}
	cout << res;
	return 0;
}
