#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	ll k = 0;
	cin >> k;
	vector<ll> A(n + 1), B(n + 1), C(m + 1), D(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i] >> B[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> C[i] >> D[i];
	}
	auto cal = [&](ld mid)
	{
		vector<ld> v;
		for (int i = 1; i <= n; ++i)
		{
			ld p = (ld)100 * A[i] - mid * (A[i] + B[i]);
			v.push_back(p);
		}
		sort(v.begin(), v.end());
		ll pivot = 0;
		int len = v.size();
		for (int i = 1; i <= m; ++i)
		{
			ld p = (ld)100 * C[i] - mid * (C[i] + D[i]);
			int idx = lower_bound(v.begin(), v.end(), -p) - v.begin();
			pivot += len - idx;
		}
		return (pivot >= k);
	};
	ld left = 0, right = 100, ans = -1;
	for (int i = 0; i < 100; ++i)
	{
		ld mid = (left + right) / 2;
		if (cal(mid))
		{
			left = mid;
			ans = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
