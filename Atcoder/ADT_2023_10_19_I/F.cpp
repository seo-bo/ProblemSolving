#include <bits/stdc++.h>
using namespace std;
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
	ll left = 1, right = INT_MAX, res = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll pivot = 0;
		for (auto& i : v)
		{
			ll a = max(0LL, i - mid);
			pivot += (a + x - 1) / x;
		}
		if (pivot <= k)
		{
			right = mid - 1;
			res = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	priority_queue<ll>pq;
	for (auto& i : v)
	{
		ll a = max(0LL, i - res);
		ll p = (a + x - 1) / x;
		i -= p * x, k -= p;
		if (i > 0)
		{
			pq.push(i);
		}
	}
	while (!pq.empty() && k)
	{
		ll cur = pq.top();
		pq.pop();
		cur -= x, k--;
		if (cur > 0)
		{
			pq.push(cur);
		}
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
