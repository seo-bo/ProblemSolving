#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0, cnt = 0;
	cin >> n >> m >> k;
	string str;
	cin >> str;
	vector<int> v(1);
	for (int i = 1; i <= n; ++i)
	{
		if (str[i - 1] == 'x')
		{
			cnt++;
			v.push_back(i);
		}
	}
	str += str;
	ll base = min(2LL, m);
	ll ans = 0, left = 0, pivot = 0;
	for (int right = 1; right <= base * n; ++right)
	{
		pivot += (str[right - 1] == 'x');
		while (pivot > k)
		{
			pivot -= (str[left++] == 'x');
		}
		ans = max(ans, right - left);
	}
	if (base == 1)
	{
		cout << ans;
		return 0;
	}
	ll p = 2 * cnt;
	for (int i = 0; i <= 2 * n; ++i)
	{
		int len = 2 * n - i;
		if (i)
		{
			p -= (str[i - 1] == 'x');
		}
		if (p > k)
		{
			continue;
		}
		ll temp = min(m - 1 - (len > n), (k - p) / cnt);
		ll res = temp * n + len;
		if (temp != m - 1 - (len > n))
		{
			res += v[(k - p) % cnt + 1] - 1;
		}
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}
