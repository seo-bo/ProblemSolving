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
	vector<int> v(n);
	int maxi = 0;
	for (auto &i : v)
	{
		cin >> i;
		maxi = max(maxi, i);
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		if (v[a - 1] == maxi)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
