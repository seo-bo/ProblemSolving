#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll op(ll a, ll b)
{
	return min(a, b);
}

ll e()
{
	return LLONG_MAX / 8;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>> A = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
	vector<vector<int>> B = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
	vector<segtree<ll, op, e>> seg(4, segtree<ll, op, e>(n + 2));
	vector<ll> v(n + 1), ans(n + 1, LLONG_MAX);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		for (int j = 0; j < 2; ++j)
		{
			ll base = v[i] * B[j][0] + i * B[j][1], temp = LLONG_MAX;
			if (!j)
			{
				temp = seg[j].prod(1, v[i]);
			}
			else
			{
				temp = seg[j].prod(v[i] + 1, n + 1);
			}
			ans[i] = min(ans[i], base + temp);
			ll p = v[i] * A[j][0] + i * A[j][1];
			seg[j].set(v[i], p);
		}
	}
	for (int i = n; i >= 1; --i)
	{
		for (int j = 2; j < 4; ++j)
		{
			ll base = v[i] * B[j][0] + i * B[j][1], temp = LLONG_MAX;
			if (j == 2)
			{
				temp = seg[j].prod(1, v[i]);
			}
			else
			{
				temp = seg[j].prod(v[i] + 1, n + 1);
			}
			ans[i] = min(ans[i], base + temp);
			ll p = v[i] * A[j][0] + i * A[j][1];
			seg[j].set(v[i], p);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
