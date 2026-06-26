#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll>tp;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<tp>>graph(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		graph[a].push_back(make_tuple(b, c, d));
		graph[b].push_back(make_tuple(a, -c, -d));
	}
	vector<pll>ans(n + 1, make_pair(LLONG_MAX, LLONG_MAX));
	ans[1] = make_pair(0, 0);
	queue<ll>q;
	q.push(1);
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		auto [x, y] = ans[cur];
		for (auto& [nv, nx, ny] : graph[cur])
		{
			if (ans[nv].first != LLONG_MAX)
			{
				continue;
			}
			ans[nv] = make_pair(x + nx, y + ny);
			q.push(nv);
		}
	}
	for (ll i = 1; i <= n; ++i)
	{
		auto [x, y] = ans[i];
		if (x == LLONG_MAX)
		{
			cout << "undecidable\n";
			continue;
		}
		cout << x << ' ' << y << '\n';
	}
	return 0;
}
