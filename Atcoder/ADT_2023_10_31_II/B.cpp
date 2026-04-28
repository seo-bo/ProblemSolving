#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, p = 0, q = 0, r = 0, s = 0;
	cin >> n >> p >> q >> r >> s;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = p, j = r; i <= q; ++i, ++j)
	{
		swap(v[i], v[j]);
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << v[i] << ' ';
	}
	return 0;
}
