#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	map<ll, ll> mm;
	mm[1] = n;
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		auto it = prev(mm.upper_bound(b));
		if (a == 2)
		{
			cout << it->second - it->first + 1 << '\n';
		}
		else
		{
			int start = it->first, end = it->second;
			mm.erase(start);
			int la = start, ra = b;
			if (la <= ra)
			{
				mm[la] = ra;
			}
			int lb = b + 1, rb = end;
			if (lb <= rb)
			{
				mm[lb] = rb;
			}
		}
	}
	return 0;
}
