#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, q = 0;
	cin >> n >> q;
	vector<ll>ans(n + 1), cnt(n + 1), pos(n + 1), flag(n + 1);
	ll left = n / 2 - 1, right = n / 2 + 1, p = 1, res = 0;
	if (n % 2)
	{
		right = n / 2 + 2;
	}
	while (left >= 0 && right <= n)
	{
		ll pivot = 2 * p - 1;
		if (n % 2)
		{
			pivot++;
		}
		ll cost = ans[left + 1] + pivot;
		ans[left--] = ans[right++] = cost;
		p++;
	}
	for (ll i = 1; i <= n; ++i)
	{
		cin >> pos[i];
		cnt[pos[i]]++;
	}
	for (ll i = 1; i <= n; ++i)
	{
		cin >> flag[i];
		if (flag[i])
		{
			res += cnt[i];
		}
	}
	while (q--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			cnt[pos[b]]--;
			cnt[c]++;
			if (flag[pos[b]] ^ flag[c])
			{
				res += (flag[pos[b]]) ? -1 : 1;
			}
			pos[b] = c;
		}
		else if (a == 2)
		{
			flag[b] ^= 1;
			res += (flag[b]) ? cnt[b] : -cnt[b];
		}
		cout << ans[res] << '\n';
	}
	return 0;
}