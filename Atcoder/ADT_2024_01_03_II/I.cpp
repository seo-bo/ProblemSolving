#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

struct Node
{
	ll prefix[2], suffix[2], maxi[2], len;
};

Node base()
{
	Node res;
	for (int i = 0; i < 2; ++i)
	{
		res.prefix[i] = res.suffix[i] = res.maxi[i] = 0;
	}
	res.len = 0;
	return res;
}

Node op(Node a, Node b)
{
	Node res;
	for (int i = 0; i < 2; ++i)
	{
		res.prefix[i] = a.prefix[i], res.suffix[i] = b.suffix[i];
		if (a.prefix[i] == a.len)
		{
			res.prefix[i] = a.len + b.prefix[i];
		}
		if (b.suffix[i] == b.len)
		{
			res.suffix[i] = a.suffix[i] + b.len;
		}
		res.maxi[i] = max({ a.maxi[i], b.maxi[i], a.suffix[i] + b.prefix[i] });
	}
	res.len = a.len + b.len;
	return res;
};

Node e()
{
	return base();
}

Node mapping(ll flag, Node x)
{
	if (!flag)
	{
		return x;
	}
	swap(x.prefix[0], x.prefix[1]);
	swap(x.suffix[0], x.suffix[1]);
	swap(x.maxi[0], x.maxi[1]);
	return x;
};

ll composition(ll a, ll b)
{
	return a ^ b;
}

ll id()
{
	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	string str;
	cin >> str;
	lazy_segtree<Node, op, e, ll, mapping, composition, id>seg(n + 3);
	for (int i = 1; i <= n; ++i)
	{
		int p = str[i - 1] - '0';
		Node res = base();
		res.len = 1;
		res.prefix[p] = res.suffix[p] = res.maxi[p] = 1;
		seg.set(i, res);
	}
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			seg.apply(b, c + 1, 1);
		}
		else
		{

			cout << seg.prod(b, c + 1).maxi[1] << '\n';
		}
	}
	return 0;
}
