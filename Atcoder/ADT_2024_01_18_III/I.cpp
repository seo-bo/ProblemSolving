#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;

struct Node
{
	int sum, mini;
};

Node op(Node a, Node b)
{
	Node res;
	res.sum = a.sum + b.sum;
	res.mini = min(a.mini, a.sum + b.mini);
	return res;
}

Node e()
{
	return Node(0, 0);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	string str;
	cin >> str;
	segtree<Node, op, e> seg(n + 3);
	for (int i = 1; i <= n; ++i)
	{
		int a = (str[i - 1] == '(') ? 1 : -1;
		seg.set(i, Node(a, a));
	}
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			int pb = (str[b - 1] == '(') ? 1 : -1;
			int pc = (str[c - 1] == '(') ? 1 : -1;
			if (pb == pc)
			{
				continue;
			}
			seg.set(b, Node(pc, pc));
			seg.set(c, Node(pb, pb));
			swap(str[b - 1], str[c - 1]);
		}
		else
		{
			auto [s, m] = seg.prod(b, c + 1);
			cout << ((!s && m >= 0) ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}
