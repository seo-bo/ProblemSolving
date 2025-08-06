#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll> pivot(63);
	for (int i = 1; i <= n; ++i)
	{
		ll ok = 0;
		cin >> ok;
		for (int j = 62; j >= 0; --j)
		{
			if (!(ok & (1LL << j)))
			{
				continue;
			}
			if (!pivot[j])
			{
				pivot[j] = ok;
				break;
			}
			ok ^= pivot[j];
		}
	}
	ll ans = 0;
	for (int i = 62; i >= 0; --i)
	{
		if (!pivot[i])
		{
			continue;
		}
		if ((ans ^ pivot[i]) > ans)
		{
			ans ^= pivot[i];
		}
	}
	cout << ans;
	return 0;
}