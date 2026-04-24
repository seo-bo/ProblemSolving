#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>visited(n + 1);
	int ans = n;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (visited[i])
		{
			continue;
		}
		ans -= (visited[a] == 0);
		visited[a] = 1;
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			cout << i << ' ';
		}
	}
	return 0;
}
