#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>base(63, 0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		for (int i = 62; i >= 0; --i)
		{
			if (!(temp & (1LL << i)))
			{
				continue;
			}
			if (!base[i])
			{
				base[i] = temp;
				break;
			}
			temp ^= base[i];
		}
	}
	ll ans = 0;
	for (int i = 62; i >= 0; --i)
	{
		ans = max(ans, ans ^ base[i]);
	}
	cout << ans;
	return 0;
}