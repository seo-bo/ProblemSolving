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
	vector<int>degree(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		degree[b]++;
	}
	int ans = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (!degree[i])
		{
			if (ans != -1)
			{
				cout << -1;
				return 0;
			}
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
