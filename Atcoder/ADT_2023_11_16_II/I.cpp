#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	vector<ll> can, open;
	ll sum = 0, ans = 0;
	int n = 0, m = 0;
	cin >> n >> m;
	while (n--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a == 0)
		{
			sum += b;
			pq.push(b);
			while (pq.size() > m)
			{
				sum -= pq.top();
				pq.pop();
			}
			ans = max(ans, sum);
		}
		if (a == 1)
		{
			can.push_back(b);
		}
		if (a == 2)
		{
			open.push_back(b);
		}
	}
	sort(can.rbegin(), can.rend());
	sort(open.rbegin(), open.rend());
	int clen = can.size(), olen = open.size();
	for (int i = 0, idx = 0, siz = m, nokori = 0; i < clen; ++i)
	{
		if (!nokori)
		{
			if (idx < olen)
			{
				nokori = open[idx++];
				siz--;
			}
			else
			{
				break;
			}
		}
		--nokori;
		pq.push(can[i]);
		sum += can[i];
		while (pq.size() > siz)
		{
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
