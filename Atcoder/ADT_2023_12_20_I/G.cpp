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
	vector<pll> ans(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> ans[i].first;
		ans[i].second = 0;
	}
	ll base = 0, time = 0, q = 0;
	cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 1)
		{
			base = b;
			time = i;
		}
		else if (a == 2)
		{
			cin >> c;
			if (ans[b].second < time)
			{
				ans[b].first = c, ans[b].second = time;
				continue;
			}
			ans[b].first += c;
		}
		else
		{
			if(ans[b].second < time)
			{
				cout << base << '\n';
				continue;
			}
			cout << base + ans[b].first << '\n';
		}
	}
	return 0;
}
