#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
#define MAX 1234567

int tree[(MAX + 5) * 4];

void update(int start, int end, int node, int idx, int delta)
{
	if (start > idx || idx > end)
	{
		return;
	}
	if (start == end)
	{
		tree[node] = max(tree[node], delta);
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, delta);
	update(mid + 1, end, node * 2 + 1, idx, delta);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
};

int query(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
	{
		return -(1 << 20);
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return max(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (int i = 0; i < n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a;
		b = i;
	}
	sort(v.begin(), v.end());
	int pre = -2, cnt = 3;
	for (auto& [a, b] : v)
	{
		int co = min(a - pre, 2);
		pre = a, cnt += co, a = cnt;
	}
	sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
		{
			return a.second < b.second;
		});
	for (auto& [a, b] : v)
	{
		vector<pii>temp = { {1,a - 2},{a,a},{a + 2,MAX} };
		int co = 0;
		for (auto& [c, d] : temp)
		{
			co = max(co, query(1, MAX, 1, c, d));
		}
		update(1, MAX, 1, a, co + 1);
	}
	cout << query(1, MAX, 1, 1, MAX);
	return 0;
}