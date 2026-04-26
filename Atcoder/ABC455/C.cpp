#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	map<ll, ll>mm;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		mm[a] += a;
	}
	priority_queue<ll>pq;
	for (auto& [a, b] : mm)
	{
		pq.push(b);
	}
	for (int i = 0; i < k && !pq.empty(); ++i)
	{
		pq.pop();
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
