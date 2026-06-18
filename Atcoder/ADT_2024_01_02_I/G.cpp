#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

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
	int n = 0, k = 0;
	cin >> n >> k;
	vector<segtree<ll, op, e>> seg(k + 1, segtree<ll, op, e>(n + 3));
	vector<ll> v(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n + 1; ++i)
	{
		seg[i % k].set(i, v[i] - v[i - 1]);
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int flag = 1, p = b - a + 1;
		for (int i = 0; i < k; ++i)
		{
			ll sum = 0;
			int st = a + i;
			if (st <= b)
			{
				sum = seg[st % k].prod(st, b + 1);
			}
			if (!i)
			{
				sum += v[a - 1];
			}
			if (i == p % k)
			{
				sum -= v[b];
			}
			if (sum)
			{
				flag = 0;
				break;
			}
		}
		cout << ((flag) ? "Yes" : "No") << '\n';
	}
	return 0;
}
