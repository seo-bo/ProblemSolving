#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0, k = 0;
	cin >> n >> x >> k;
	vector<ll>in, out, pos;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		ll b = a * x, c = a * 200 - b;
		in.push_back(b), out.push_back(c);
		pos.push_back(b), pos.push_back(c);
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	int idx = 0, jdx = 0, cnt = 0;
	for (auto& i : pos)
	{
		while (idx < n && i == in[idx])
		{
			cnt++, idx++;
		}
		if (cnt >= k)
		{
			ll g = gcd(i, 100);
			if (g == 100)
			{
				cout << i / 100;
			}
			else
			{
				cout << i / g << "/" << 100 / g;
			}
			return 0;
		}
		while (jdx < n && i == out[jdx])
		{
			cnt--, jdx++;
		}
	}
	cout << -1;
	return 0;
}