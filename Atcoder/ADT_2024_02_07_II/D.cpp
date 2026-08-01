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
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 2)
		{
			cout << v[b] << '\n';
			continue;
		}
		cin >> c;
		v[b] = c;
	}
	return 0;
}
