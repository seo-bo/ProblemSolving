#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<pll> v(n);
	ll sum = 0;
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
		sum += b;
	}
	sort(v.begin(), v.end());
	ll idx = 0, time = 1;
	while (1)
	{
		if (sum <= k)
		{
			cout << time;
			return 0;
		}
		if (idx < n)
		{
			time = max(time, v[idx].first);
		}
		while (idx < n && time >= v[idx].first)
		{
			sum -= v[idx].second;
			idx++;
		}
		time++;
	}
	return 0;
}
