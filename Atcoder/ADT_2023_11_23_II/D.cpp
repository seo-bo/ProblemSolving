#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0;
	cin >> n >> x;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	int ans = 0;
	vector<bool> visited(n + 1);
	while (!visited[x])
	{
		ans++;
		visited[x] = true;
		x = v[x];
	}
	cout << ans;
	return 0;
}
