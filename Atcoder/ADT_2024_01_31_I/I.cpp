#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	string str;
	cin >> n >> str;
	vector<ll>need;
	for (ll i = 0; i < n; ++i)
	{
		if (str[i] == '.')
		{
			need.push_back(i);
		}
	}
	vector<ll>div;
	for (ll i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			div.push_back(i);
			if (i != n / i)
			{
				div.push_back(n / i);
			}
		}
	}
	sort(div.begin(), div.end());
	div.pop_back();
	vector<ll>two(n + 1, 1);
	for (ll i = 1; i <= n; ++i)
	{
		two[i] = (two[i - 1] * 2) % MOD;
	}
	ll len = div.size(), ans = 0;
	vector<ll>res(len);
	for (ll i = 0; i < len; ++i)
	{
		vector<ll>visited(div[i]);
		ll siz = div[i];
		for (auto& j : need)
		{
			ll nxt = j % div[i];
			if (visited[nxt])
			{
				continue;
			}
			siz--;
			visited[nxt] = 1;
		}
		ll now = two[siz];
		for (ll j = 0; j < len; ++j)
		{
			if (div[i] % div[j] == 0)
			{
				now = (now - res[j] + MOD) % MOD;
			}
		}
		res[i] = now;
		ans = (ans + now) % MOD;
	}
	cout << ans;
	return 0;
}
