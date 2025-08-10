#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>degree(n + 1), res(n + 1);
		vector<vector<int>>graph(n + 1);
		for (int i = 0; i < n - 1; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
			degree[a]++;
			degree[b]++;
		}
		if (n == 2)
		{
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (degree[i] == 1)
			{
				ans++;
				for (auto& j : graph[i])
				{
					res[j]++;
				}
			}
		}
		cout << ans - *max_element(res.begin(), res.end()) << '\n';
	}
	return 0;
}
