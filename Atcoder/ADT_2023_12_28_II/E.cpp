#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	while (q--)
	{
		int a = 0;
		cin >> a;
		ll it = lower_bound(v.begin(), v.end(), a) - v.begin();
		cout << n - it << '\n';
	}
	return 0;
}
