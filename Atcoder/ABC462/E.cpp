#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll a = 0, b = 0, x = 0, y = 0;
		cin >> a >> b >> x >> y;
		x = llabs(x), y = llabs(y);
		ll p = min(x, y), pivot = min(2 * a, 2 * b); // 좌/우 -> 상/하 세트 1 vs 상/하 -> 좌/우 세트 2
		x -= p, y -= p;
		ll ans = pivot * p;
		p = max(x, y);
		ll d = p / 2, co = d * min(a + b, 2 * pivot); // 직선 or 대각 좌 1 상 1 + 좌 1 상 -1
		if (x && p % 2)
		{
			co += min(a, b + pivot); // 직선 or 3칸
		}
		if (y && p % 2)
		{
			co += min(b, a + pivot);
		}
		cout << ans + co << '\n';
	}
	return 0;
}
