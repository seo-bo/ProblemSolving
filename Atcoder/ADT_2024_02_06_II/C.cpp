#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>visited(361);
	visited[360] = true;
	for (int i = 0, a = 0; i < n; ++i)
	{
		int b = 0;
		cin >> b;
		a = (a + b) % 360;
		visited[a] = 1;
	}
	int ans = 1;
	for (int i = 1, cnt = 1; i <= 360; ++i)
	{
		if (visited[i])
		{
			ans = max(ans, cnt);
			cnt = 1;
			continue;
		}
		cnt++;
	}
	cout << ans;
	return 0;
}
