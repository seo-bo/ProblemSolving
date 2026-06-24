#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	deque<pll>dq;
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			if (!dq.empty() && dq.back().first == b)
			{
				dq.back().second += c;
			}
			else
			{
				dq.push_back(make_pair(b, c));
			}
		}
		else
		{
			ll ans = 0;
			while (!dq.empty() && b)
			{
				ll p = min(dq.front().second, b);
				ans += p * dq.front().first;
				b -= p;
				dq.front().second -= p;
				if (!dq.front().second)
				{
					dq.pop_front();
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
