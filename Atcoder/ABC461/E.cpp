#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MAX 300010

ll op(ll a, ll b)
{
	return a + b;
}

ll e()
{
	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>h(MAX + 1), w(MAX + 1);
	segtree<ll, op, e>segh(MAX + 1), segw(MAX + 1);
	segh.set(0, n), segw.set(0, n);
	ll ans = 0;
	for (int i = 1; i <= q; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			int p = h[b];
			ans += segw.prod(p, i);
			segh.set(p, segh.get(p) - 1);
			segh.set(i, segh.get(i) + 1);
			h[b] = i;
		}
		else
		{
			int p = w[b];
			ans -= segh.prod(p + 1, i);
			segw.set(p, segw.get(p) - 1);
			segw.set(i, segw.get(i) + 1);
			w[b] = i;
		}
		cout << ans << '\n';
	}
	return 0;
}
