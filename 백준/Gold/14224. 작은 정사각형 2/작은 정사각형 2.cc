#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	map<int, vector<int>>xx;
	vector<pii>pos(n);
	for (auto& [a, b] : pos)
	{
		cin >> a >> b;
		xx[a--].push_back(b--);
	}
	for (auto& [a, b] : xx)
	{
		sort(b.begin(), b.end());
	}
	int len = pos.size();
	auto cal = [&](ll x, ll y, ll c)
		{
			ll ex = x + c, ey = y + c, cnt = 0;
			for (auto it = xx.upper_bound(x); it != xx.end() && it->first < ex; ++it)
			{
				auto& pp = it->second;
				cnt += lower_bound(pp.begin(), pp.end(), ey) - upper_bound(pp.begin(), pp.end(), y);
			}
			return (cnt >= k);
		};
	ll res = LLONG_MAX;
	for (auto& [x, _] : pos)
	{
		for (auto& [_, y] : pos)
		{
			ll left = 2, right = INT_MAX, ans = INT_MAX;
			while (left <= right)
			{
				ll mid = (left + right) / 2;
				if (cal(x, y, mid))
				{
					ans = mid;
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			res = min(res, ans);
		}
	}
	cout << res * res;
	return 0;
}