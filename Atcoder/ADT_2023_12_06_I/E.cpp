#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, t = 0;
	cin >> n >> t;
	ll sum = 0;
	vector<ll> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	t -= (t / sum) * sum;
	for (int i = 1; i <= n; ++i)
	{
		if(t - v[i] <= 0)
		{
			cout << i << ' ' << t;
			return 0;
		}
		t -= v[i];
	}
	return 0;
}
