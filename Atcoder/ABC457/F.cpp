#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
#define MAX 2e5

vector<ll>tree(4 * (MAX + 5)), lazy(4 * (MAX + 5), 1);

void lazy_update(int start, int end, int node)
{
	if (lazy[node] != 1)
	{
		tree[node] = tree[node] * lazy[node] % MOD;
		if (start != end)
		{
			lazy[node * 2] = lazy[node] * lazy[node * 2] % MOD;
			lazy[node * 2 + 1] = lazy[node] * lazy[node * 2 + 1] % MOD;
		}
		lazy[node] = 1;
	}
}

void mul(int start, int end, int node, int left, int right, ll delta)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		lazy[node] = lazy[node] * delta % MOD;
		lazy_update(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	mul(start, mid, node * 2, left, right, delta);
	mul(mid + 1, end, node * 2 + 1, left, right, delta);
	lazy_update(start, mid, node * 2);
	lazy_update(mid + 1, end, node * 2 + 1);
	tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

void update(int start, int end, int node, int idx, ll delta)
{
	if (idx < start || end < idx)
	{
		return;
	}
	lazy_update(start, end, node);
	if (start == end)
	{
		tree[node] = (tree[node] + delta) % MOD;
		return;
	}
	int mid = (start + end) / 2;
	if (idx <= mid)
	{
		update(start, mid, node * 2, idx, delta);
	}
	else
	{
		update(mid + 1, end, node * 2 + 1, idx, delta);
	}
	lazy_update(start, mid, node * 2);
	lazy_update(mid + 1, end, node * 2 + 1);
	tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

ll query(int start, int end, int node, int idx)
{
	if (idx < start || end < idx)
	{
		return 0LL;
	}
	lazy_update(start, end, node);
	if (start == end)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return (query(start, mid, node * 2, idx) + query(mid + 1, end, node * 2 + 1, idx)) % MOD;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> v[i];
	}
	update(1, n, 1, n, 1);
	for (int i = n - 1; i >= 1; --i)
	{
		ll idx = i + v[i], co = query(1, n, 1, idx);
		if (i != n - 1 && v[i] == v[i + 1])
		{
			mul(1, n, 1, 1, n, n - i - 1);
		}
		else
		{
			mul(1, n, 1, 1, n, 0);
		}
		update(1, n, 1, idx, co), update(1, n, 1, i, co);
	}
	cout << tree[1] % MOD;
	return 0;
}
