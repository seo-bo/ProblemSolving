#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<int> v(m);
	for (auto &i : v)
	{
		cin >> i;
	}
	while (q--)
	{
		int a = 0;
		cin >> a;
		if (m == a)
		{
			v[a - 1] = min(v[a - 1] + 1, n);
		}
		else if (v[a - 1] + 1 < v[a])
		{
			v[a - 1]++;
		}
	}
	for (auto &i : v)
	{
		cout << i << ' ';
	}
	return 0;
}
