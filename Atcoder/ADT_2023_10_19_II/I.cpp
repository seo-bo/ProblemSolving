#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, T = 0, ans = 0;
	cin >> n >> T;
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		pq.push(a);
		T -= a;
	}
	if (T)
	{
		pq.push(T);
	}
	while (pq.size() > 1)
	{
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans;
	return 0;
}
