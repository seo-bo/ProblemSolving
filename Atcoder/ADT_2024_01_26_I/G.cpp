#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int k = 0, len = str.size();
	cin >> k;
	vector<int>v;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '.')
		{
			v.push_back(i);
		}
	}
	v.push_back(len);
	int ans = 0;
	for (int i = 0; i < len; ++i)
	{
		auto it = lower_bound(v.begin(), v.end(), i) - v.begin();
		int idx = min((int)v.size() - 1, (int)it + k);
		ans = max(ans, v[idx] - i);
	}
	cout << ans;
	return 0;
}
