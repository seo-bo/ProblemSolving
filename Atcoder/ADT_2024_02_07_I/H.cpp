#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	map<ll, ll>dp;
	dp[x] = 0;
	for (int i = n; i >= 1; --i)
	{
		map<ll, ll>temp;
		for (auto& [a, b] : dp)
		{
			ll p = a / v[i];
			for (ll j = 0; j <= 1; ++j)
			{
				ll nxt = llabs((p + j) * v[i] - a);
				if (temp.find(nxt) == temp.end() || temp[nxt] > b + p + j)
				{
					temp[nxt] = b + p + j;
				}
			}
		}
		dp = move(temp);
	}
	cout << dp[0];
	return 0;
}
