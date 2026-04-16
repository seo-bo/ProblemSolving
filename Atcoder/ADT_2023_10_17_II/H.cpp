#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	vector<pii>cost(n);
	for (int i = 1; i <= n - 1; ++i)
	{
		auto& [a, b] = cost[i];
		cin >> a >> b;
	}
	vector<ll>dp(841);
	for (int i = 0; i <= 840; ++i)
	{
		dp[i] = i;
		for (int j = 1; j <= n - 1; ++j)
		{
			auto [a, b] = cost[j];
			dp[i] += (a - dp[i] % a) % a + b;
		}
		dp[i] -= i;
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0;
		cin >> a;
		a += x;
		cout << a + dp[a % 840] + y << '\n';
	}
	return 0;
}
