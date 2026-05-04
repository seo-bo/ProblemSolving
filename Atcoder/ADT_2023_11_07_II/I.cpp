#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>tp;
#define MAX 300000

ll tree[(MAX + 4) * 4];

void update(ll start, ll end, ll node, ll idx, ll delta)
{
	if (idx > end || idx < start)
	{
		return;
	}
	if (start == end)
	{
		tree[node] = delta;
		return;
	}
	ll mid = (start + end) / 2;
	update(start, mid, node * 2, idx, delta);
	update(mid + 1, end, node * 2 + 1, idx, delta);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

ll query(ll start, ll end, ll node, ll left, ll right, ll k)
{
	if (start > right || end < left || tree[node] < k)
	{
		return LLONG_MAX;
	}
	if (start == end)
	{
		return start;
	}
	ll mid = (start + end) / 2, temp = query(start, mid, node * 2, left, right, k);
	if (temp != LLONG_MAX)
	{
		return temp;
	}
	return query(mid + 1, end, node * 2 + 1, left, right, k);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>graph(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	vector<pll>dist(n + 1, make_pair(LLONG_MAX, LLONG_MIN));
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	ll p = 0, d = 0;
	cin >> p;
	for (ll i = 0; i < p; ++i)
	{
		ll a = 0;
		cin >> a;
		dist[a] = make_pair(0, 0);
		pq.push(make_tuple(0, 0, a));
	}
	cin >> d;
	vector<ll>go(d + 1);
	for (ll i = 1; i <= d; ++i)
	{
		cin >> go[i];
		update(1, d, 1, i, go[i]);
	}
	while (!pq.empty())
	{
		auto [day, now, ver] = pq.top();
		pq.pop();
		now = -now;
		if (dist[ver].first < day || (dist[ver].first == day && dist[ver].second > now))
		{
			continue;
		}
		for (auto& [nv, nc] : graph[ver])
		{
			ll nxt = day, co = now - nc;
			if (co < 0)
			{
				nxt = query(1, d, 1, day + 1, d, nc);
				if (nxt == LLONG_MAX)
				{
					continue;
				}
				co = go[nxt] - nc;
			}
			if (dist[nv].first > nxt || (dist[nv].first == nxt && dist[nv].second < co))
			{
				dist[nv] = make_pair(nxt, co);
				pq.push(make_tuple(nxt, -co, nv));
			}
		}
	}
	for (ll i = 1; i <= n; ++i)
	{
		cout << ((dist[i].first == LLONG_MAX) ? -1 : dist[i].first) << '\n';
	}
	return 0;
}
