#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, p = 0, q = 0;
		cin >> n >> p >> q;
		vector<int>now(p + 1);
		for (int i = 1; i <= n; ++i)
		{
			int a = 0;
			cin >> a;
			now[a]++;
		}
		vector<vector<ll>>graph(p + 1, vector<ll>(p + 1, (1 << 20)));
		for (int i = 1; i <= p; ++i)
		{
			graph[i][i] = 0;
		}
		for (int i = 0; i < q; ++i)
		{
			int a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			graph[a][b] = graph[b][a] = min(graph[a][b], (ll)c);
		}
		for (int k = 1; k <= p; ++k)
		{
			for (int i = 1; i <= p; ++i)
			{
				for (int j = 1; j <= p; ++j)
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
		ll ans = -1, res = LLONG_MAX;
		for (int i = 1; i <= p; ++i)
		{
			ll temp = 0;
			for (int j = 1; j <= p; ++j)
			{
				temp += graph[i][j] * graph[i][j] * now[j];
			}
			if (temp < res)
			{
				res = temp;
				ans = i;
			}
		}
		cout << ans << ' ' << res << '\n';
	}
	return 0;
}