#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int> per(10, 0);
	string str;
	cin >> str;
	sort(str.rbegin(), str.rend());
	for (auto &i : str)
	{
		per[i - '0']++;
	}
	int ans = 0;
	ll lim = stoll(str);
	if (!lim)
	{
		cout << 1;
		return 0;
	}
	for (ll i = 1, len = 1, p = 10; i * i <= lim; ++i)
	{
		ll o = i * i;
		if (o / p)
		{
			++len, p *= 10;
		}
		int pp = n - len;
		if (per[0] < pp)
		{
			continue;
		}
		int flag = 1;
		vector<int> temp = per;
		temp[0] -= pp;
		ll x = o;
		while (x)
		{
			if (--temp[x % 10] == -1)
			{
				flag = 0;
				break;
			}
			x /= 10;
		}
		ans += flag;
	}
	cout << ans;
	return 0;
}
