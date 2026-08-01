#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

struct Node
{
	int prefix[2], suffix[2], sum[2];
	int len;
};

Node op(Node a, Node b)
{
	if (!a.len)
	{
		return b;
	}
	if (!b.len)
	{
		return a;
	}
	Node res;
	res.len = a.len + b.len;
	for (int i = 0; i < 2; ++i)
	{
		res.prefix[i] = a.prefix[i];
		if (a.prefix[i] == a.len)
		{
			res.prefix[i] += b.prefix[i];
		}
		res.suffix[i] = b.suffix[i];
		if (b.suffix[i] == b.len)
		{
			res.suffix[i] += a.suffix[i];
		}
		res.sum[i] = max({ a.sum[i],b.sum[i], a.suffix[i] + b.prefix[i] });
	}
	return res;
}

Node e()
{
	return Node();
}

Node mapping(int f, Node a)
{
	if (f)
	{
		swap(a.prefix[0], a.prefix[1]);
		swap(a.suffix[0], a.suffix[1]);
		swap(a.sum[0], a.sum[1]);
	}
	return a;
}

int composition(int f, int g)
{
	return f ^ g;
}

int id()
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
	lazy_segtree<Node, op, e, int, mapping, composition, id>seg(n + 5);
	for (int i = 1; i <= n; ++i)
	{
		int p = str[i - 1] - '0';
		Node temp;
		temp.len = temp.suffix[p] = temp.prefix[p] = temp.sum[p] = 1;
		temp.suffix[p ^ 1] = temp.prefix[p ^ 1] = temp.sum[p ^ 1] = 0;
		seg.set(i, temp);
	}
	while (q--)
	{
		int a = 0, l = 0, r = 0;
		cin >> a >> l >> r;
		if (a == 1)
		{
			seg.apply(l, r + 1, 1);
		}
		else
		{
			cout << seg.prod(l, r + 1).sum[1] << '\n';
		}
	}
	return 0;
}
