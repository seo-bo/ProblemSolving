#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> per(k);
	for (auto &i : per)
	{
		cin >> i;
	}
	vector<pll> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto &[a, b] = v[i];
		cin >> a >> b;
	}
	vector<ll> res(n + 1, LLONG_MAX / 8);
	for (auto &i : per)
	{
		auto [x, y] = v[i];
		for (int j = 1; j <= n; ++j)
		{
			auto [nx, ny] = v[j];
			res[j] = min(res[j], (nx - x) * (nx - x) + (ny - y) * (ny - y));
		}
	}
	ll ans = -1;
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, res[i]);
	}
	cout << fixed << setprecision(15) << (long double)sqrtl(ans);
	return 0;
}
