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
	vector<int>ans(n + 1);
	map<string, int>mm;
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		mm[str] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		ans[mm[str]] = 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ((ans[i]) ? "Yes\n" : "No\n");
	}
	return 0;
}
