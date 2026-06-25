#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, d = 0, p = 0;
	cin >> n >> d >> p;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	while (!v.empty())
	{
		ll temp = 0;
		for (int i = 0; i < d && !v.empty(); ++i)
		{
			temp += v.back();
			v.pop_back();
		}
		ans += min(temp, p);
	}
	cout << ans;
	return 0;
}
