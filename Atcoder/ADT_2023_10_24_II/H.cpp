#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<set<int>>graph(n + 1);
	vector<int>degree(n + 1);
	int ans = n;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			ans -= (++degree[b] == 1) + (++degree[c] == 1);
			graph[b].insert(c), graph[c].insert(b);
		}
		else
		{
			cin >> b;
			ans += 1 - (degree[b] == 0), degree[b] = 0;
			for (auto& i : graph[b])
			{
				ans += (--degree[i] == 0);
				graph[i].erase(b);
			}
			set<int>().swap(graph[b]);
		}
		cout << ans << '\n';
	}
	return 0;
}
