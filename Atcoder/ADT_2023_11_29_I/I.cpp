#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<ll, ll> row, col;
	map<pll, ll> pos;
	vector<pll> R, C;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		row[a] += c, col[b] += c;
		R.push_back(make_pair(a, 0));
		C.push_back(make_pair(b, 0));
		pos[make_pair(a, b)] = c;
	}
	sort(R.begin(), R.end());
	R.erase(unique(R.begin(), R.end()), R.end());
	sort(C.begin(), C.end());
	C.erase(unique(C.begin(), C.end()), C.end());
	for (auto &[a, b] : R)
	{
		b = row[a];
	}
	for (auto &[a, b] : C)
	{
		b = col[a];
	}
	sort(C.begin(), C.end(), [&](const pll &a, const pll &b)
		 { return a.second > b.second; });
	ll ans = LLONG_MIN;
	for (auto &[x, co1] : R)
	{
		for (auto &[y, co2] : C)
		{
			ll res = co1 + co2;
			if (pos.find(make_pair(x, y)) == pos.end())
			{
				ans = max(ans, res);
				break;
			}
			ans = max(ans, res - pos[make_pair(x, y)]);
		}
	}
	cout << ans;
	return 0;
}
