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
	vector<int> ans(1);
	cin >> ans[0];
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0;
		cin >> a;
		int d = ((ans.back() < a) ? 1 : -1), now = ans.back() + d;
		while (now != a)
		{
			ans.push_back(now);
			now += d;
		}
		ans.push_back(a);
	}
	for (auto &i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
