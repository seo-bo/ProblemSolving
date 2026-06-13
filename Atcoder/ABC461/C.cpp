#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, m = 0;
	cin >> n >> k >> m;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> b >> a;
	}
	sort(v.rbegin(), v.rend());
	vector<ll>nokori;
	set<int>s;
	ll ans = 0;
	for (auto& [a, b] : v)
	{
		if (m - s.size() == 0 || s.find(b) != s.end())
		{
			nokori.push_back(a);
			continue;
		}
		s.insert(b);
		ans += a;
	}
	for (int i = 0; i < k - m; ++i)
	{
		ans += nokori[i];
	}
	cout << ans;
	return 0;
}
