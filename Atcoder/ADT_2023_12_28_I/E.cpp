#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll sum = 0;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	ll x = 0;
	cin >> x;
	ll ans = x / sum * n;
	x %= sum;
	for (int i = 0; i < n; ++i)
	{
		ans++;
		if (x - v[i] < 0)
		{
			break;
		}
		x -= v[i];
	}
	cout << ans;
	return 0;
}
