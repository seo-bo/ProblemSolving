#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, tot = 0;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		tot += v[i];
	}
	int p = (tot + 1) / 2;
	for (int i = 1; i <= n; ++i)
	{
		if (p <= v[i])
		{
			cout << i << ' ' << min(p, v[i]);
			return 0;
		}
		p -= v[i];
	}
	return 0;
}
