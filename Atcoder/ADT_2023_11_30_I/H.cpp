#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<ll> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	set<ll> s = {0};
	for (int i = 0; i < k; ++i)
	{
		auto it = s.begin();
		ll pivot = *it;
		s.erase(it);
		for (int j = 1; j <= n; ++j)
		{
			s.insert(pivot + v[j]);
		}
	}
	cout << *(s.begin());
	return 0;
}
