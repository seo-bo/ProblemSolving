#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	v.push_back(0);
	sort(v.rbegin(), v.rend());
	auto cal = [&](ll a, ll b)
		{
			return b * (b + 1) / 2 - a * (a + 1) / 2;
		};
	ll pivot = v[0], cnt = 1, ans = 0;
	for (int i = 1; i <= n && m; ++i)
	{
		ll term = min(m, (pivot - v[i]) * cnt);
		ll A = term / cnt, B = term % cnt;
		ans += cal(pivot - A, pivot) * cnt + (pivot - A) * B, m -= term;
		pivot = v[i], cnt++;
	}
	cout << ans;
	return 0;
}
