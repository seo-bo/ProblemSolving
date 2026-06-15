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
	vector<int>v(n + 1);
	for (int i = 0; i < 4 * n - 1; ++i)
	{
		int a = 0;
		cin >> a;
		v[a]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (v[i] != 4)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
