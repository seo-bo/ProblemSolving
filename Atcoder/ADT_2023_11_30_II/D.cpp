#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1));
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			for (int k = j + 1; k <= n; ++k)
			{
				ans += (graph[i][j] && graph[j][k] && graph[k][i]);
			}
		}
	}
	cout << ans;
	return 0;
}
