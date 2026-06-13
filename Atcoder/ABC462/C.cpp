#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	sort(v.begin(), v.end());
	ll p = LLONG_MAX, ans = 0;
	for (auto& [a, b] : v)
	{
		ans += (b < p);
		p = min(p, b);
	}
	cout << ans;
	return 0;
}
