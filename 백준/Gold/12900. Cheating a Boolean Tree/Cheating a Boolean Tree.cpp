#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	for (int _ = 1; _ <= T; ++_)
	{
		int n = 0, k = 0;
		cin >> n >> k;
		int lim = (n - 1) / 2;
		vector<pii>v(n + 1, make_pair(-1, -1));
		vector<int>cost(n + 1, -1);
		for (int i = 1; i <= lim; ++i)
		{
			cin >> v[i].first >> v[i].second;
		}
		for (int i = lim + 1; i <= n; ++i)
		{
			cin >> cost[i];
		}
		vector<int>base = { INT_MAX, INT_MAX };
		function<vector<int>(int, int)> dfs = [&](int parent, int node)
			{
				if (v[node].first == -1)
				{
					return ((cost[node]) ? vector<int>{INT_MAX, 0} : vector<int>{ 0, INT_MAX });
				}
				vector<int>res = base, left = dfs(node, node * 2), right = dfs(node, node * 2 + 1);
				for (int i = 0; i <= v[node].second; ++i)
				{
					for (int j = 0; j <= 1; ++j)
					{
						for (int z = 0; z <= 1; ++z)
						{
							if (left[j] == INT_MAX || right[z] == INT_MAX)
							{
								continue;
							}
							int p = ((v[node].first ^ i) ? (j & z) : (j | z));
							res[p] = min(res[p], left[j] + right[z] + i);
						}
					}
				}
				return res;
			};
		vector<int>ans = dfs(0, 1);
		cout << format("Case #{}: ", _);
		if (ans[k] == INT_MAX)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << ans[k] << '\n';
	}
	return 0;
}