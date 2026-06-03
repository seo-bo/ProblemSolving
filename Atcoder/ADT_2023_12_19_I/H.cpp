#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, q = 0, x = 0;
	cin >> n >> q >> x;
	vector<ll> v(n + 1), prefix(2 * n + 2);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	for (int i = n + 1; i <= 2 * n; ++i)
	{
		prefix[i] = prefix[i - 1] + v[i - n];
	}
	vector<ll> ans(n + 1), visited(n + 1, -1), res;
	ll tot = prefix[n], idx = 1;
	while (visited[idx] == -1)
	{
		visited[idx] = res.size();
		res.push_back(idx);
		ll a = x / tot, b = x % tot;
		ans[idx] += a * n;
		if (b)
		{
			ll nxt = lower_bound(prefix.begin() + 1, prefix.end(), prefix[idx - 1] + b) - prefix.begin();
			ans[idx] += nxt - idx + 1;
			idx = nxt % n + 1;
		}
	}
	ll start = visited[idx], len = res.size() - visited[idx];
	while (q--)
	{
		ll a = 0;
		cin >> a;
		a--;
		if (a < start)
		{
			cout << ans[res[a]] << '\n';
		}
		else
		{
			cout << ans[res[start + (a - start) % len]] << '\n';
		}
	}
	return 0;
}
