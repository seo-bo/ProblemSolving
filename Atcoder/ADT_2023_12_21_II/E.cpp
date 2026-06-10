#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pld> v(n);
	ld time = 0, ans = 0;
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
		time += a / b;
	}
	time /= 2;
	for (auto &[a, b] : v)
	{
		ans += min(a, time * b);
		time -= min(a / b, time);
	}
	cout << fixed << setprecision(12) << ans;
	return 0;
}
