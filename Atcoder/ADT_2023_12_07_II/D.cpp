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
	vector<string> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	vector<int> cost(m + 1);
	map<string, int> mm;
	for (int i = 1; i <= m; ++i)
	{
		string str;
		cin >> str;
		mm[str] = i;
	}
	for (int i = 0; i <= m; ++i)
	{
		cin >> cost[i];
	}
	int ans = 0;
	for (auto &i : v)
	{
		if (mm.find(i) == mm.end())
		{
			ans += cost[0];
			continue;
		}
		ans += cost[mm[i]];
	}
	cout << ans;
	return 0;
}
