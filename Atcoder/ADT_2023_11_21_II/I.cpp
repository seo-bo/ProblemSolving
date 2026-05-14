#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto cal = [&](ll ax, ll ay, ll bx, ll by, ll co)
	{
		return (llabs(ax - bx) + llabs(ay - by)) * co;
	};
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll b = 0, k = 0, sx = 0, sy = 0, ex = 0, ey = 0;
		cin >> b >> k >> sx >> sy >> ex >> ey;
		ll ans = cal(sx, sy, ex, ey, k);
		vector<tp> st = {{sx, sy / b * b, cal(sx, sy, sx, sy / b * b, k)},
						 {sx, ((sy / b) + 1) * b, cal(sx, sy, sx, (sy / b + 1) * b, k)},
						 {(sx / b) * b, sy, cal(sx, sy, (sx / b) * b, sy, k)},
						 {(sx / b + 1) * b, sy, cal(sx, sy, (sx / b + 1) * b, sy, k)}};
		vector<tp> ed = {{ex, ey / b * b, cal(ex, ey, ex, ey / b * b, k)},
						 {ex, ((ey / b) + 1) * b, cal(ex, ey, ex, (ey / b + 1) * b, k)},
						 {(ex / b) * b, ey, cal(ex, ey, (ex / b) * b, ey, k)},
						 {(ex / b + 1) * b, ey, cal(ex, ey, (ex / b + 1) * b, ey, k)}};
		auto sv = [&](ll ax, ll ay, ll bx, ll by)
		{
			ll res = LLONG_MAX / 8;
			if (ax == bx && ax % b == 0)
			{
				res = min(res, llabs(ay - by));
			}
			if (ay == by && ay % b == 0)
			{
				res = min(res, llabs(ax - bx));
			}
			if (ax % b == 0 && bx % b == 0)
			{
				ll temp = LLONG_MAX / 8;
				for (auto &i : {ay / b * b, (ay / b + 1) * b, by / b * b, (by / b + 1) * b})
				{
					temp = min(temp, llabs(ay - i) + llabs(by - i));
				}
				res = min(res, llabs(ax - bx) + temp);
			}
			if (ay % b == 0 && by % b == 0)
			{
				ll temp = LLONG_MAX / 8;
				for (auto &i : {ax / b * b, (ax / b + 1) * b, bx / b * b, (bx / b + 1) * b})
				{
					temp = min(temp, llabs(ax - i) + llabs(bx - i));
				}
				res = min(res, llabs(ay - by) + temp);
			}
			if ((ay % b == 0 && bx % b == 0) || (ax % b == 0 && by % b == 0))
			{
				res = min(res, llabs(ax - bx) + llabs(ay - by));
			}
			return res;
		};
		for (int i = 0; i < 4; ++i)
		{
			auto [ax, ay, ac] = st[i];
			for (int j = 0; j < 4; ++j)
			{
				auto [bx, by, bc] = ed[j];
				ll temp = ac + bc + sv(ax, ay, bx, by);
				ans = min(ans, temp);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
