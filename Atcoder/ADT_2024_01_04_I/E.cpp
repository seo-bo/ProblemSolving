#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	set<ll>s;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		s.insert(a);
		ll p1 = a + x, p2 = a - x;
		if (s.find(p1) != s.end() || s.find(p2) != s.end())
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
