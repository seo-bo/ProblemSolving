#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n + 1), prefix(n + 1);
	for (int i = 1, flag = 1; i <= n; ++i, flag ^= 1)
	{
		cin >> v[i];
		if (!v[i])
		{
			continue;
		}
		ll co = ((flag) ? (v[i] - v[i - 1]) : 0);
		prefix[i] = prefix[i - 1] + co;
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		int left = upper_bound(v.begin() + 1, v.end(), a) - v.begin();
		int right = upper_bound(v.begin() + 1, v.end(), b) - v.begin() - 1;
		ll ans = prefix[right] - prefix[left];
		if (left % 2)
		{
			ans += v[left] - a;
		}
		if (right % 2 == 0)
		{
			ans += b - v[right];
		}
		cout << ans << '\n';
	}
	return 0;
}
