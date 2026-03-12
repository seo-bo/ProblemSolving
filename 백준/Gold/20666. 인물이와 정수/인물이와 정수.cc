#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n + 1);
	ll left = 1, right = 0, ans = -1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		right = max(right, v[i] + 5);
	}
	int t = 0;
	cin >> t;
	vector<vector<pll>>graph(n + 1);
	for (int i = 1; i <= t; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		v[b] += c;
		right = max(right, v[b] + 5);
	}
	auto cal = [&](ll mid)
		{
			vector<ll>temp = v;
			queue<int>q;
			for (int i = 1; i <= n; ++i)
			{
				if (temp[i] <= mid)
				{
					q.push(i);
					temp[i] = LLONG_MAX;
				}
			}
			int cnt = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				cnt++;
				for (auto& [a, b] : graph[cur])
				{
					temp[a] -= b;
					if (temp[a] <= mid)
					{
						q.push(a);
						temp[a] = LLONG_MAX;
					}
				}
			}
			return cnt >= m;
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}