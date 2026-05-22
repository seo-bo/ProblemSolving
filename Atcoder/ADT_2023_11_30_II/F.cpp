#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<ll, ll> mm;
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			mm[b]++;
		}
		else if (a == 3)
		{
			auto it = mm.begin(), jt = prev(mm.end());
			cout << jt->first - it->first << '\n';
		}
		else
		{
			cin >> b >> c;
			mm[b] -= c;
			if (mm[b] <= 0)
			{
				mm.erase(b);
			}
		}
	}
	return 0;
}
