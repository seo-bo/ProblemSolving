#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<vector<int>>per(2);
	vector<int>v = { 1,INT_MAX };
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		per[str[i] - '0'].push_back(a);
		v.push_back(a);
	}
	for (int i = 0; i < 2; ++i)
	{
		sort(per[i].begin(), per[i].end());
	}
	int ans = 0, len = per[1].size();
	for (auto& i : v)
	{
		int it = lower_bound(per[0].begin(), per[0].end(), i) - per[0].begin();
		int jt = lower_bound(per[1].begin(), per[1].end(), i) - per[1].begin();
		ans = max(ans, it + len - jt);
	}
	cout << ans;
	return 0;
}
