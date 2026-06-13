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
	vector<vector<int>>ans(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			ans[b].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i].size() << ' ';
		for(auto & j : ans[i])
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}
