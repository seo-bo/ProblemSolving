#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int s = 0, t = 0, m = 0;
	cin >> s >> t >> m;
	vector<vector<int>>graph(s + t + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	auto cal = [&](int x)
		{
			vector<int>ans(t + 1);
			queue<tp>q;
			q.push(make_tuple(x, 0, 0)); // now, parent, dist
			while (!q.empty())
			{
				auto [now, parent, d] = q.front();
				q.pop();
				if (d == 2)
				{
					int p = now - s;
					if (ans[p])
					{
						cout << x << ' ' << ans[p] << ' ' << now << ' ' << parent;
						exit(0);
					}
					ans[now - s] = parent;
					continue;
				}
				for (auto& i : graph[now])
				{
					if (i == parent)
					{
						continue;
					}
					q.push(make_tuple(i, now, d + 1));
				}
			}
		};
	for (int i = s + 1; i <= s + t; ++i)
	{
		cal(i);
	}
	cout << -1;
	return 0;
}
