#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MAX 1000000

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0;
	cin >> n >> d;
	vector<ll>prefix(MAX + 10);
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		b = b - d + 1;
		if (a < b)
		{
			prefix[a]++, prefix[b]--;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= MAX; ++i)
	{
		prefix[i] += prefix[i - 1];
		ans += prefix[i] * (prefix[i] - 1) / 2;
	}
	cout << ans;
	return 0;
}
