#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[31][31][31][1001];

ll op(ll a, ll b)
{
	return a + b;
}

ll e()
{
	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	string str, base = "KEY";
	cin >> str;
	ll len = str.size(), k = 0;
	cin >> k;
	vector<vector<ll>>pos(3);
	segtree<ll, op, e>seg(len + 3);
	for (ll i = 0; i < len; ++i)
	{
		ll idx = -1;
		for (ll j = 0; j < 3; ++j)
		{
			if (str[i] == base[j])
			{
				idx = j;
				break;
			}
		}
		pos[idx].push_back(i + 1);
		seg.set(i + 1, 1);
	}
	ll alen = pos[0].size(), blen = pos[1].size(), clen = pos[2].size();
	function<ll(ll, ll, ll, ll)> dfs = [&](ll idx, ll a, ll b, ll score)
		{
			if (idx == len)
			{
				return (ll)(score <= k);
			}
			if (dp[idx][a][b][score] != -1)
			{
				return dp[idx][a][b][score];
			}
			ll res = 0, c = idx - a - b;
			if (a < alen)
			{
				ll p = pos[0][a], sum = seg.prod(1, p);
				seg.set(p, 0);
				res += dfs(idx + 1, a + 1, b, score + sum);
				seg.set(p, 1);
			}
			if (b < blen)
			{
				ll p = pos[1][b], sum = seg.prod(1, p);
				seg.set(p, 0);
				res += dfs(idx + 1, a, b + 1, score + sum);
				seg.set(p, 1);
			}
			if (c < clen)
			{
				ll p = pos[2][c], sum = seg.prod(1, p);
				seg.set(p, 0);
				res += dfs(idx + 1, a, b, score + sum);
				seg.set(p, 1);
			}
			return dp[idx][a][b][score] = res;
		};
	cout << dfs(0, 0, 0, 0);
	return 0;
}
