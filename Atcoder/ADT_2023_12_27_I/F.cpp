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
	auto cal = [&](pll A, pll B,pll C)
		{
			auto [a, b] = A;
			auto [c, d] = B;
			auto [e, f] = C;
			return ((c - a) * (f - b) - (d - b) * (e - a) != 0);
		};
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				ans += cal(v[i], v[j], v[k]);
			}
		}
	}
	cout << ans;
	return 0;
}
