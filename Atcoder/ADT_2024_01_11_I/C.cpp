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
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<int>visited(n + 1), ans;
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			visited[v[i]] = 1;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
