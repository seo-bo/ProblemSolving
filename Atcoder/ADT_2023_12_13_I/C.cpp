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
	vector<int> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	vector<int> per(n + 1);
	iota(per.begin(), per.end(), v[0]);
	for (int i = 0; i < n; ++i)
	{
		if (v[i] != per[i])
		{
			cout << per[i];
			return 0;
		}
	}
	return 0;
}
