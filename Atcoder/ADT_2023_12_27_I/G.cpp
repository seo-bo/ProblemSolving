#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int N = 1 << 20;
	set<int>s;
	for (int i = 0; i < N; ++i)
	{
		s.insert(i);
	}
	vector<ll>ans(N, -1);
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			auto it = s.lower_bound(b % N);
			if (it == s.end())
			{
				it = s.begin();
			}
			ans[*it] = b;
			s.erase(it);
		}
		else
		{
			cout << ans[b % N] << '\n';
		}
	}
	return 0;
}
