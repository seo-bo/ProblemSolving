#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<pld> A(n), B(m);
	for (auto &[a, b] : A)
	{
		cin >> a >> b;
	}
	for (auto &[a, b] : B)
	{
		cin >> a >> b;
	}
	auto cal = [&](ld mid)
	{
		vector<ld> temp;
		for (auto &[a, b] : A)
		{
			ld co = a * 100 - mid * (a + b);
			temp.push_back(co);
		}
		sort(temp.begin(), temp.end());
		ll cnt = 0;
		for (auto &[a, b] : B)
		{
			ld co = a * 100 - mid * (a + b);
			auto it = lower_bound(temp.begin(), temp.end(), -co) - temp.begin();
			cnt += n - it;
		}
		return (cnt >= k);
	};
	ld left = 0, right = 100, ans = -1;
	for (int i = 1; i <= 100; ++i)
	{
		ld mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
