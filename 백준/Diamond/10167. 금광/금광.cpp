#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;

struct Node
{
	ll sum, prefix, suffix, maxi;
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, xx = 1, yy = 1;
	cin >> n;
	vector<tp>temp(n);
	vector<ll>px, py;
	unordered_map<ll, ll>mx, my;
	for (auto& [a, b, c] : temp)
	{
		cin >> a >> b >> c;
		px.push_back(a);
		py.push_back(b);
	}
	sort(px.begin(), px.end());
	sort(py.begin(), py.end());
	for (ll i = 0; i < n; ++i)
	{
		if (!mx[px[i]])
		{
			mx[px[i]] = xx++;
		}
		if (!my[py[i]])
		{
			my[py[i]] = yy++;
		}
	}
	vector<vector<pll>>v(xx + 1);
	for (auto& [a, b, c] : temp)
	{
		v[mx[a]].push_back(make_pair(my[b], c));
	}
	for (ll i = 1; i <= xx; ++i)
	{
		sort(v[i].begin(), v[i].end());
	}
	vector<Node>tree;
	auto comb = [&](Node& left, Node& right)
		{
			Node res;
			res.sum = left.sum + right.sum;
			res.prefix = max(left.prefix, left.sum + right.prefix);
			res.suffix = max(right.suffix, right.sum + left.suffix);
			res.maxi = max({ left.maxi, right.maxi, left.suffix + right.prefix });
			return res;
		};
	function<void(ll, ll, ll)> init = [&](ll start, ll end, ll node)
		{
			if (start == end)
			{
				tree[node] = { 0,0,0,0 };
				return;
			}
			ll mid = (start + end) >> 1;
			init(start, mid, node * 2);
			init(mid + 1, end, node * 2 + 1);
			tree[node] = comb(tree[node * 2], tree[node * 2 + 1]);
		};
	function<void(ll, ll, ll, ll, ll)> update = [&](ll start, ll end, ll node, ll idx, ll delta)
		{
			if (start > idx || end < idx)
			{
				return;
			}
			if (start == end)
			{
				tree[node].sum += delta;
				tree[node].prefix += delta;
				tree[node].suffix += delta;
				tree[node].maxi += delta;
				return;
			}
			ll mid = (start + end) >> 1;
			if (idx <= mid)
			{
				update(start, mid, node * 2, idx, delta);
			}
			else
			{
				update(mid + 1, end, node * 2 + 1, idx, delta);
			}
			tree[node] = comb(tree[node * 2], tree[node * 2 + 1]);
		};
	ll ans = LLONG_MIN;
	for (ll i = 1; i <= xx; ++i)
	{
		vector<Node>(4 * (yy + 3)).swap(tree);
		init(1, yy, 1);
		for (ll j = i; j <= xx; ++j)
		{
			for (auto& [a, b] : v[j])
			{
				update(1, yy, 1, a, b);
				// 여기서 ans를 갱신하면 사각형이 아닐지도?
			}
			ans = max(ans, tree[1].maxi);
		}
	}
	cout << ans;
	return 0;
}