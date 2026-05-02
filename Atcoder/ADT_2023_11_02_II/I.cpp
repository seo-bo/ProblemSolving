#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
	ll sum, prefix;
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	string str;
	cin >> str;
	vector<Node>tree((n + 2) * 4), base = { {1,0},{-1,-1} };
	function<void(int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int delta)
		{
			if (idx < start || idx > end)
			{
				return;
			}
			if (start == end)
			{
				tree[node] = base[delta];
				return;
			}
			int mid = (start + end) / 2;
			update(start, mid, node * 2, idx, delta);
			update(mid + 1, end, node * 2 + 1, idx, delta);
			tree[node].sum = (tree[node * 2].sum + tree[node * 2 + 1].sum);
			tree[node].prefix = min(tree[node * 2].prefix, tree[node * 2].sum + tree[node * 2 + 1].prefix);
		};
	function<Node(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			if (left > end || right < start)
			{
				return Node(0, 0);
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			int mid = (start + end) / 2;
			Node l = query(start, mid, node * 2, left, right);
			Node r = query(mid + 1, end, node * 2 + 1, left, right);
			return Node(l.sum + r.sum, min(l.prefix, l.sum + r.prefix));
		};
	for (int i = 1; i <= n; ++i)
	{
		int p = (str[i - 1] == ')');
		update(1, n, 1, i, p);
	}
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			if (str[b - 1] == str[c - 1])
			{
				continue;
			}
			int p = (str[b - 1] == '(');
			update(1, n, 1, b, p), update(1, n, 1, c, p ^ 1);
			swap(str[b - 1], str[c - 1]);
		}
		else
		{
			auto [s, pre] = query(1, n, 1, b, c);
			cout << ((s == 0 && pre >= 0) ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}
