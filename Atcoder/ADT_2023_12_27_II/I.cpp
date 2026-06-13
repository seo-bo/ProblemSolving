#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	vector<vector<ll>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<ll>v = { (xb < xc), (xb > xc), (yb < yc), (yb > yc) };
	vector<pll>pos;
	for (int i = 0; i < 4; ++i)
	{
		if (!v[i])
		{
			continue;
		}
		ll nx = xb + dir[i][0], ny = yb + dir[i][1];
		pos.push_back(make_pair(nx, ny));
	}
	ll ans = LLONG_MAX, len = pos.size();
	for (int i = 0; i < len; ++i)
	{
		auto [x1, y1] = pos.front();
		ll co = llabs(x1 - xa) + llabs(y1 - ya) + llabs(xc - xb) + llabs(yc - yb) + 2 * (len == 2);
		if (ya == yb && y1 == yb)
		{
			int flag = (x1 < xb && xb < xa) | (x1 > xb && xb > xa);
			co += 2 * flag;
		}
		if (xa == xb && x1 == xb)
		{
			int flag = (y1 < yb && yb < ya) | (y1 > yb && yb > ya);
			co += 2 * flag;
		}
		ans = min(ans, co);
		swap(pos.front(), pos.back());
	}
	cout << ans;
	return 0;
}
