#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pll>v;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		a <<= 1;
		b <<= 1;
		if (c == 1)
		{
			b = 0;
		}
		if (d == 1)
		{
			a >>= 1;
			b >>= 1;
		}
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), [&](const pll& a, const pll& b)
		{
			return a.first < b.first;
		});
	ll sx = 0, sy = 0, ans = 0;
	cin >> sx >> sy;
	sx *= 2, sy *= 2;
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	int cnt = 0, idx = 0;
	while (cnt < m)
	{
		while (idx < n && v[idx].first <= sx)
		{
			pq.push(v[idx].second);
			idx++;
		}
		if (!pq.empty())
		{
			ans += max(pq.top() / 2 - sy / 2, 0LL);
			pq.pop();
			sx += 2;
			sy += 2;
			cnt++;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}