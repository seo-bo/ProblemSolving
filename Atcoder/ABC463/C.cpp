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
	vector<pll>v(n + 4, make_pair(LLONG_MAX, LLONG_MAX));
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a >> b;
	}
	vector<ll>suffix(n + 3);
	for (int i = n; i >= 1; --i)
	{
		suffix[i] = max(suffix[i + 1], v[i].first);
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0;
		cin >> a;
		auto it = lower_bound(v.begin() + 1, v.end(), a + 1, [&](const pll& A, ll p)
			{
				return A.second < p;
			});
		cout << suffix[it - v.begin()] << '\n';
	}
	return 0;
}
