#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (auto& i : v)
	{
		ll temp = 0;
		cin >> temp;
		i = max(0LL, temp - i);
	}
	deque<pll>dq;
	ll nxt = 0, cnt = 0, ans = 0;
	for (int i = 0; i < n; ++i)
	{
		while (!dq.empty() && i - dq.front().first == k)
		{
			cnt -= dq.front().second;
			dq.pop_front();
		}
		v[i] = max(0LL, v[i] - nxt);
		ll pivot = (v[i] + k - 1) / k;
		ans += pivot;
		cnt += pivot;
		dq.push_back(make_pair(i, pivot));
		nxt = nxt + (pivot * k) - cnt;
	}
	cout << ans;
	return 0;
}