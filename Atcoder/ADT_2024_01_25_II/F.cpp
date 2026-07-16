#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>v(k);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		v[i % k].push_back(a);
	}
	for (auto& i : v)
	{
		sort(i.rbegin(), i.rend());
	}
	int pre = INT_MIN;
	for (int i = 0, j = 0; i < n; ++i, j = (j + 1) % k)
	{
		if (pre > v[j].back())
		{
			cout << "No";
			return 0;
		}
		pre = v[j].back();
		v[j].pop_back();
	}
	cout << "Yes";
	return 0;
}
