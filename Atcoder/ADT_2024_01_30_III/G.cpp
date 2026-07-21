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
	vector<ll>v(n + 1), time(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	int q = 0;
	cin >> q;
	ll num = -1, t = -1;
	for (int i = 1; i <= q; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 1)
		{
			num = b, t = i;
		}
		if (a == 2)
		{
			cin >> c;
			if (time[b] < t)
			{
				v[b] = num;
				time[b] = t;
			}
			v[b] += c;
		}
		if (a == 3)
		{
			if (time[b] < t)
			{
				v[b] = num;
				time[b] = t;
			}
			cout << v[b] << '\n';
		}
	}
	return 0;
}
