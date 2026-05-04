#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	long double ans = 0;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	for (auto& [a, b] : v)
	{
		for (auto& [c, d] : v)
		{
			ans = max(ans, (long double)sqrtl((a - c) * (a - c) + (b - d) * (b - d)));
		}
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
