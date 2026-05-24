#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<string, ll> psl;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll> cnt(n + 1), potencial(n + 1);
	vector<psl> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto &[a, b] = v[i];
		cin >> a;
		b = i;
		for (auto &j : a)
		{
			if (j == 'X')
			{
				cnt[i]++;
				continue;
			}
			potencial[i] += j - '0';
		}
	}
	sort(v.begin() + 1, v.end(), [&](const psl &A, const psl &B)
		 {
			auto [as,a] = A;
			auto [bs,b] = B;
			return cnt[a] * potencial[b] > cnt[b] * potencial[a]; });
	ll ans = 0, x = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (auto &j : v[i].first)
		{
			if (j == 'X')
			{
				x++;
				continue;
			}
			ans += (j - '0') * x;
		}
	}
	cout << ans;
	return 0;
}
