#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>>graph(100001);
int sum[100001] = { 0, };
int parent[100001] = { 0, };
int depth[100001] = { 0, };
int head[100001] = { 0, };
int chain[100001] = { 0, };
int tree[400004] = { 0, };
int rev[100001] = { 0, };

int ver = 1;

void update(int start, int end, int node, int idx)
{
	if (idx > end || idx < start)
	{
		return;
	}
	if (start == end)
	{
		tree[node] ^= 1;
		return;
	}
	int mid = (start + end) >> 1;
	update(start, mid, node * 2, idx);
	update(mid + 1, end, node * 2 + 1, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int start, int end, int node, int left, int right)
{
	if (left > end || right < start || !tree[node])
	{
		return 0;
	}
	if (start == end)
	{
		return start;
	}
	int mid = (start + end) >> 1;
	int L = query(start, mid, node * 2, left, right);
	if (L)
	{
		return L;
	}
	return query(mid + 1, end, node * 2 + 1, left, right);
}

int dfs(int par, int node, int d)
{
	parent[node] = par;
	depth[node] = d;
	int cnt = 1;
	for (auto& i : graph[node])
	{
		if (par == i)
		{
			continue;
		}
		cnt += dfs(node, i, d + 1);
	}
	return sum[node] = cnt;
}

void hld(int par, int node)
{
	rev[ver] = node;
	chain[node] = ver++;
	bool flag = true;
	for (auto& i : graph[node])
	{
		if (i == par)
		{
			continue;
		}
		if (flag)
		{
			head[i] = head[node];
			flag = false;
		}
		else
		{
			head[i] = i;
		}
		hld(node, i);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	head[1] = 1;
	dfs(0, 1, 1);
	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), [&](const int& a, const int& b)
			{
				return sum[a] > sum[b];
			});
	}
	hld(0, 1);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			update(1, n, 1, chain[b]);
		}
		else
		{
			int x = b, ans = -1;
			while (x)
			{
				int res = query(1, n, 1, chain[head[x]], chain[x]);
				if (res)
				{
					ans = rev[res];
				}
				x = parent[head[x]];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}