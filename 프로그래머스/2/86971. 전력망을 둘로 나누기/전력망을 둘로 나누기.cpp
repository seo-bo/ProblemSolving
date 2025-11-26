#include <bits/stdc++.h>

using namespace std;
int solution(int n, vector<vector<int>>wires)
{
	vector<int>dp(n + 1);
	vector<vector<int>>graph(n + 1);
	for (auto& i : wires)
	{
		graph[i[0]].push_back(i[1]);
		graph[i[1]].push_back(i[0]);
	}
	function<int(int, int)> dfs = [&](int parent, int node)
		{
			dp[node] = 1;
			for (auto& i : graph[node])
			{
				if (parent == i)
				{
					continue;
				}
				dp[node] += dfs(node, i);
			}
			return dp[node];
		};
	dfs(0, 1);
	int answer = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		answer = min(answer, abs(n - 2 * dp[i]));
	}
	return answer;
}