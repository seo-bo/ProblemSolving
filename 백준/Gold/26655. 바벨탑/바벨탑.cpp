#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
		v[i] = (v[i] - 20) / 2;
	}
	vector<pll>tree((n + 3) * 4, make_pair(LLONG_MAX, -1LL));
	function<void(ll, ll, ll)> build = [&](ll start, ll end, ll node)
		{
			if (start == end)
			{
				tree[node] = make_pair(v[start], start);
				return;
			}
			ll mid = (start + end) >> 1;
			build(start, mid, node * 2);
			build(mid + 1, end, node * 2 + 1);
			tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
		};
	function<pll(ll, ll, ll, ll, ll)> query = [&](ll start, ll end, ll node, ll left, ll right)
		{
			if (right < start || end < left)
			{
				return make_pair(LLONG_MAX, -1LL);
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			ll mid = (start + end) >> 1;
			return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
		};
	build(1, n, 1);
	ll wei = 0, cnt = 0;
	auto cal = [&](ll ok)
		{
			ll r1 = 0, r2 = 0;
			vector<ll>t = { 20,15,10,5 };
			for (auto& i : t)
			{
				if (ok < i)
				{
					continue;
				}
				ll pivot = ok / i;
				r1 += 4LL * pivot * i;
				r2 += pivot * 4;
				ok %= i;
			}
			wei += r1;
			cnt += r2;
		};
	function<void(ll, ll, ll)>dfs = [&](ll left, ll right, ll pre)
		{
			if (left == right)
			{
				cal(v[left] - pre);
				return;
			}
			ll res = 0;
			auto [co, pos] = query(1, n, 1, left, right);
			cal(co - pre);
			if (left <= pos - 1)
			{
				dfs(left, pos - 1, co);
			}
			if (right >= pos + 1)
			{
				dfs(pos + 1, right, co);
			}
		};
	dfs(1, n, 0);
	cout << wei << ' ' << cnt;
	return 0;
}