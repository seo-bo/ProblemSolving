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
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll left = 0, right = INT_MAX, ans = -1;
	auto cal = [&](ll mid)
		{
			ll cnt = 0;
			for (auto& i : v)
			{
				ll p = max(0LL, i - mid);
				cnt += (p + x - 1) / x;
			}
			return (cnt <= k);
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	priority_queue<ll>pq;
	for (auto& i : v)
	{
		ll p = max(0LL, i - ans);
		ll co = (p + x - 1) / x;
		k -= co, i = max(0LL, i - co * x);
		if (i)
		{
			pq.push(i);
		}
	}
	while (!pq.empty() && k)
	{
		ll cur = pq.top();
		pq.pop();
		ll co = max(0LL, cur - x);
		if (co)
		{
			pq.push(co);
		}
		k--;
	}
	ll res = 0;
	while (!pq.empty())
	{
		res += pq.top();
		pq.pop();
	}
	cout << res;
	return 0;
}
