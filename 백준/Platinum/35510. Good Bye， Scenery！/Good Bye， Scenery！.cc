#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<pii>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			auto& [a, b] = v[i];
			cin >> a;
			b = i;
		}
		sort(v.rbegin(), v.rend() - 1);
		vector<ll>BIT(n + 1);
		auto update = [&](int idx)
			{
				while (idx <= n)
				{
					BIT[idx]++;
					idx += idx & -idx;
				}
			};
		auto query = [&](int idx)
			{
				ll res = 0;
				while (idx)
				{
					res += BIT[idx];
					idx -= idx & -idx;
				}
				return res;
			};
		priority_queue<int>pq;
		vector<int>temp;
		for (int i = n, idx = 1; i >= 1; --i)
		{
			while (idx <= n && v[idx].first >= i)
			{
				auto& [a, b] = v[idx++];
				pq.push(b);
			}
			if (pq.empty())
			{
				break;
			}
			temp.push_back(pq.top());
			pq.pop();
		}
		if (temp.size() != n)
		{
			cout << -1 << '\n';
			continue;
		}
		ll ans = 0;
		while (!temp.empty())
		{
			int cur = temp.back();
			temp.pop_back();
			ans += query(n) - query(cur);
			update(cur);
		}
		cout << ans << '\n';
	}
	return 0;
}