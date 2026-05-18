#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<tp> v(n);
	for (int i = 0; i < n; ++i)
	{
		auto &[a, b, c] = v[i];
		cin >> a >> b;
		c = i + 1;
	}
	sort(v.begin(), v.end(), [&](const tp &x, const tp &y)
		 {
		auto [ax,bx,xco] = x;
		auto [ay,by,yco] = y;
		ll a = ax * (ay+by), b = ay * (ax+bx);
		if(a == b)
		{
			return xco < yco;
		}
		return a > b; });
	for (auto &[a, b, c] : v)
	{
		cout << c << ' ';
	}
	return 0;
}
