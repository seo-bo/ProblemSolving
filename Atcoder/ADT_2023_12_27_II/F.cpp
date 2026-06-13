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
	string str;
	cin >> str;
	vector<vector<int>>v(2);
	vector<int>x(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
		int b = str[i] - '0';
		v[b].push_back(x[i]);
	}
	for (auto& i : v)
	{
		sort(i.begin(), i.end());
	}
	int ans = 0,len = v[1].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = -5; j <= 5; ++j)
		{
			int co = x[i] + j;
			int it = lower_bound(v[0].begin(), v[0].end(), co) - v[0].begin();
			int jt = lower_bound(v[1].begin(), v[1].end(), co) - v[1].begin();
			ans = max(ans, it + len - jt);
		}
	}
	cout << ans;
	return 0;
}
