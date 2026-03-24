#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0;
	cin >> q;
	while (q--)
	{
		priority_queue<tp>pq;
		int n = 0, k = 0;
		cin >> n >> k;
		vector<bool>visited(n + 1);
		vector<int>A(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			int a = 0;
			cin >> a;
			pq.push(make_tuple(a - A[i], a, i, 1));
			pq.push(make_tuple(A[i] - a, A[i], i, 0));
		}
		ll ans = 0;
		int ma = n / 2 + ((n & 1) ? (k + 1) / 2 : k / 2);
		vector<int>cnt(2, ma);
		while (!pq.empty())
		{
			auto [_, co, idx, tp] = pq.top();
			pq.pop();
			if (visited[idx] || !cnt[tp])
			{
				continue;
			}
			--cnt[tp], ans += co, visited[idx] = true;
		}
		cout << ans << '\n';
	}
	return 0;
}