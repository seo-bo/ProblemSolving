#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll tot = 0;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
		tot += i;
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	while (!v.empty())
	{
		ll len = v.size(), p = (tot + len - 1) / len;
		ans += llabs(v.back() - p);
		tot -= p;
		v.pop_back();
	}
	cout << ans / 2;
	return 0;
}
