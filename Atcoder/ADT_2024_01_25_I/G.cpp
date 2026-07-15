#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int l = 0, q = 0;
	cin >> l >> q;
	set<int>s = { 0,l };
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			s.insert(b);
		}
		else
		{
			auto nxt = s.lower_bound(b);
			auto pre = prev(nxt);
			cout << *nxt - *pre << '\n';
		}
	}
	return 0;
}
