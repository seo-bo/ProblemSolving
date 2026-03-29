#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	ll ans = 0;
	deque<pll>dq = { {0,0} };
	auto cal = [&](int idx, ll a)
		{
			ans += a;
			while (!dq.empty() && idx - k - 1 > dq.front().second)
			{
				dq.pop_front();
			}
			ll co = dq.front().first + a;
			while (!dq.empty() && dq.back().first >= co)
			{
				dq.pop_back();
			}
			dq.push_back(make_pair(co, idx));
		};
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		cal(i, a);
	}
	cal(n + 1, 0);
	cout << ans - dq.front().first;
	return 0;
}