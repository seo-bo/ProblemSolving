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
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (i >= m)
		{
			ans.push_back(a);
		}
	}
	while (ans.size() < n)
	{
		ans.push_back(0);
	}
	for (auto &i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
