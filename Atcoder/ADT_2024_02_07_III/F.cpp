#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, x = 0;
	cin >> n >> k >> x;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	auto cal = [&](ll mid)
		{
			ll cnt = 0;
			for (int i = 1; i <= n; ++i)
			{
				ll pivot = max(0LL, v[i] - mid);
				cnt += (pivot + x - 1) / x;
			}
			return cnt <= k;
		};
	ll left = 0, right = INT_MAX, res = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
		{
			res = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	priority_queue<ll>pq;
	for (int i = 1; i <= n; ++i)
	{
		ll pivot = max(0LL, v[i] - res);
		ll temp = (pivot + x - 1) / x;
		k -= temp, v[i] -= temp * x;
		if (v[i] > 0)
		{
			pq.push(v[i]);
		}
	}
	for (int i = 0; i < k && !pq.empty(); ++i)
	{
		ll cur = pq.top();
		pq.pop();
		if (cur - x <= 0)
		{
			continue;
		}
		pq.push(cur - x);
	}
	ll ans = 0;
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}
