#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		auto [sx, sy] = v[i];
		for (int j = 0; j < n; ++j)
		{
			auto [ex, ey] = v[j];
			ans = max(ans, (sx - ex) * (sx - ex) + (sy - ey) * (sy - ey));
		}
	}
	cout << fixed << setprecision(15) << (double)sqrtl(ans);
	return 0;
}
