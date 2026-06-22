#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, d = 0;
	cin >> n >> d;
	vector<pll>v(n);
	for (auto& [b, a] : v)
	{
		cin >> a >> b;
	}
	sort(v.begin(), v.end());
	ll ans = 0, pre = -1;
	for (auto& [right, left] : v)
	{
		if (left <= pre)
		{
			continue;
		}
		ans++;
		pre = right + d - 1;
	}
	cout << ans;
	return 0;
}
