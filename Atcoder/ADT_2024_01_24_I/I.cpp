#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MUL 998244353
#define MOD 1000000007

ll p[1111112];

struct Node
{
	ll prefix, suffix, len;
};

Node op(Node a, Node b)
{
	Node res;
	res.prefix = (a.prefix * p[b.len] % MOD + b.prefix) % MOD;
	res.suffix = (b.suffix * p[a.len] % MOD + a.suffix) % MOD;
	res.len = a.len + b.len;
	return res;
}

Node e()
{
	return Node(0, 0, 0);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	p[0] = 1;
	for (int i = 1; i <= 1111111; ++i)
	{
		p[i] = (p[i - 1] * MUL) % MOD;
	}
	int n = 0, q = 0;
	cin >> n >> q;
	string str;
	cin >> str;
	segtree<Node, op, e>seg(n + 10);
	for (int i = 1; i <= n; ++i)
	{
		int o = str[i - 1] - 'a' + 1;
		seg.set(i, Node(o, o, 1));
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			char c;
			cin >> c;
			int o = c - 'a' + 1;
			seg.set(b, Node(o, o, 1));
			continue;
		}
		int c = 0;
		cin >> c;
		Node res = seg.prod(b, c + 1);
		cout << ((res.prefix == res.suffix) ? "Yes" : "No") << '\n';
	}
	return 0;
}
