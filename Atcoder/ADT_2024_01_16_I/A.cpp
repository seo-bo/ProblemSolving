#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0;
	cin >> n >> d;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 2; i <= n; ++i)
	{
		if (v[i] - v[i - 1] <= d)
		{
			cout << v[i];
			return 0;
		}
	}
	cout << -1;
	return 0;
}
