#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int op(int a, int b)
{
	return max(a, b);
}

int e()
{
	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	segtree<int, op, e> seg(m + 5);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		pq.push(make_pair(a, b));
		seg.set(a, a);
	}
	vector<ll> ans(m + 5);
	for (int i = 1; i <= m; ++i)
	{
		while (!pq.empty() && pq.top().first < i)
		{
			auto [a, b] = pq.top();
			pq.pop();
			if (b == -1)
			{
				break;
			}
			seg.set(a, 0), seg.set(b, b);
			pq.push(make_pair(b, -1));
		}
		if (pq.size() < n)
		{
			break;
		}
		int len = seg.all_prod();
		ans[len - i + 1]++, ans[m - i + 2]--;
	}
	for (int i = 1; i <= m; ++i)
	{
		ans[i] += ans[i - 1];
		cout << ans[i] << ' ';
	}
	return 0;
}
