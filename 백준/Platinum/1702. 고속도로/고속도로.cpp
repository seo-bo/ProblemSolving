#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll>tp;
typedef pair<ll, ll>pll;

int main(void) // 뭔소리임?
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, s = 0, e = 0;
	cin >> n >> m >> s >> e;
	vector<vector<tp>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		graph[a].push_back(make_tuple(b, c, d));
		graph[b].push_back(make_tuple(a, c, d));
	}
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	vector<set<pll>>ok(n + 1);
	pq.push(make_tuple(0, 0, s));
	ok[s].insert(make_pair(0, 0)); // 비용, 시간
	while (!pq.empty())
	{
		auto [co, ti, ver] = pq.top();
		pq.pop();
		if (ok[ver].find(make_pair(co, ti)) == ok[ver].end())
		{
			continue;
		}
		for (auto& [nv, nc, nt] : graph[ver])
		{
			ll nxtt = nt + ti, nxtc = nc + co;
			bool flag = true;
			vector<pll>temp;
			for (auto& [cc, tt] : ok[nv])
			{
				if (cc <= nxtc && tt <= nxtt) // 둘다 딸리니까 좋은 경로라고 볼수가
				{
					flag = false;
				}
				else if (cc >= nxtc && tt >= nxtt) // 둘다 이기니까 ㄱㅊ
				{
					temp.push_back(make_pair(cc, tt));
				}
			}
			if (!flag)
			{
				continue;
			}
			for (auto& [a, b] : temp)
			{
				ok[nv].erase(make_pair(a, b));
			}
			ok[nv].insert(make_pair(nxtc, nxtt));
			pq.push(make_tuple(nxtc, nxtt, nv));
		}
	}
	cout << ok[e].size();
	return 0;
}