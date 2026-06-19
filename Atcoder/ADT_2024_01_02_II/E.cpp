#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<int>s;
	for (ll i = 0; i <= 62; ++i)
	{
		if (n & (1LL << i))
		{
			s.push_back(2);
		}
		else
		{
			s.push_back(0);
		}
	}
	while (s.back() == 0)
	{
		s.pop_back();
	}
	reverse(s.begin(), s.end());
	for (auto& i : s)
	{
		cout << i;
	}
	return 0;
}
