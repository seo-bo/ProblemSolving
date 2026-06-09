#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pll> v = {{1, 0}};
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	ll temp = 0, sum = 0, ans = LLONG_MIN;
	priority_queue<ll> pq;
	for (int i = n; i >= 0 && k >= 0; --i)
	{
		auto [a, b] = v[i];
		if (a == 1)
		{
			ans = max(ans, b + sum);
			k--;
			while (!pq.empty() && pq.size() > k)
			{
				sum += pq.top();
				pq.pop();
			}
			continue;
		}
		if (b > 0)
		{
			sum += b;
			continue;
		}
		pq.push(b);
		while (!pq.empty() && pq.size() > k)
		{
			sum += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}
