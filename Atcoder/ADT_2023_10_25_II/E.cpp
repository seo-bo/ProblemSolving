#include <bits/stdc++.h>
using namespace std;
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
		for (auto& j : { a - x,a + x })
		{
			if (s.find(j) != s.end())
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
