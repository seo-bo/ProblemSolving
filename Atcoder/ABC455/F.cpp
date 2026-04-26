#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
#define INV 499122177

struct Node
{
	ll dsum, sum;
};

vector<Node>tree(100001 * 4 + 1);
vector<ll>lazy(100001 * 4 + 1);

void lazy_update(int start, int end, int node) // a^2 + b^2 .... -> (a+?)^2 + (b+?)^2 .... -> [a^2 + b^2] + [2*? *(a+b...)] + [len * ? * ?]
{
	if (lazy[node])
	{
		int len = end - start + 1;
		tree[node].dsum = (tree[node].dsum + 2 * lazy[node] % MOD * tree[node].sum % MOD + lazy[node] * lazy[node] % MOD * len % MOD) % MOD;
		tree[node].sum = (tree[node].sum + lazy[node] * len % MOD) % MOD;
		if (start != end)
		{
			lazy[node * 2] = (lazy[node * 2] + lazy[node]) % MOD;
			lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % MOD;
		}
		lazy[node] = 0;
	}
}

void update(int start, int end, int node, int left, int right, ll delta)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		lazy[node] = delta;
		lazy_update(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, delta);
	update(mid + 1, end, node * 2 + 1, left, right, delta);
	tree[node].dsum = (tree[node * 2].dsum + tree[node * 2 + 1].dsum) % MOD;
	tree[node].sum = (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;
}

Node query(int start, int end, int node, int left, int right)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return Node();
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	Node l = query(start, mid, node * 2, left, right), r = query(mid + 1, end, node * 2 + 1, left, right);
	return { (l.dsum + r.dsum) % MOD, (l.sum + r.sum) % MOD };
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		update(1, n, 1, a, b, c);
		auto [ds, s] = query(1, n, 1, a, b);
		cout << (s * s % MOD - ds + MOD) % MOD * INV % MOD << '\n';
	}
	return 0;
}
