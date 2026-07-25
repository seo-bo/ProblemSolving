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
	map<ll, pll>mm;
	vector<vector<pll>>v(n);
	for (int i = 0; i < n; ++i)
	{
		int p = 0;
		cin >> p;
		for (int j = 0; j < p; ++j)
		{
			ll a = 0, b = 0;
			cin >> a >> b;
			if (mm.find(a) == mm.end())
			{
				mm[a] = make_pair(b, 0);
			}
			else if (mm[a].first < b)
			{
				mm[a].second = mm[a].first;
				mm[a].first = b;
			}
			else if (mm[a].second < b)
			{
				mm[a].second = b;
			}
			v[i].push_back(make_pair(a, b));
		}
	}
	ll ans = 0;
	for (auto& i : v)
	{
		ll flag = 0;
		for (auto& [a, b] : i)
		{
			if (mm[a].first == b && mm[a].first != mm[a].second)
			{
				flag = 1;
				break;
			}
		}
		ans += flag;
	}
	cout << ans + (ans < n);
	return 0;
}
