#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

ll cost[300001];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<pll>s;
	map<ll, set<pll>>mm;
	auto cal = [&](auto now, int flag)
		{
			ll co = now->first, idx = now->second;
			ll pivot = LLONG_MAX, a = -1, b = -1;
			if (now != s.begin())
			{
				auto jt = prev(now);
				if (pivot > llabs(co - jt->first))
				{
					pivot = llabs(co - jt->first);
					a = jt->second, b = idx;
				}
			}
			if (next(now) != s.end())
			{
				auto jt = next(now);
				if (pivot > llabs(co - jt->first))
				{
					pivot = llabs(co - jt->first);
					a = idx, b = jt->second;
				}
			}
			if (pivot == LLONG_MAX)
			{
				return;
			}
			if (!flag)
			{
				if (mm.find(pivot) == mm.end())
				{
					return;
				}
				mm[pivot].erase(make_pair(a, b));
				if (mm[pivot].empty())
				{
					mm.erase(pivot);
				}
			}
			else
			{
				mm[pivot].insert(make_pair(a, b));
			}
		};
	ll q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			cost[b] = c;
			auto now = s.lower_bound(make_pair(c, b));
			if (now != s.begin())
			{
				auto pr = prev(now);
				cal(pr, 0);
			}
			if (now != s.end())
			{
				cal(now, 0);
			}
			s.insert(make_pair(c, b));
			now = s.find(make_pair(c, b));
			if (now != s.begin())
			{
				cal(prev(now), 1);
			}
			cal(now, 1);
			if (next(now) != s.end())
			{
				cal(next(now), 1);
			}
			continue;
		}
		auto [A, B] = *mm.begin()->second.begin();
		auto it = s.find(make_pair(cost[A], A));
		ll st = -1, ed = -1;
		if (it != s.begin())
		{
			auto pr = prev(it);
			cal(pr, 0);
			st = pr->second;
		}
		cal(it, 0);
		cal(next(it), 0);
		if (next(next(it)) != s.end())
		{
			auto nx = next(next(it));
			cal(nx, 0);
			ed = nx->second;
		}
		s.erase(make_pair(cost[A], A));
		s.erase(make_pair(cost[B], B));
		if (st != -1)
		{
			cal(s.find(make_pair(cost[st], st)), 1);
		}
		if (ed != -1)
		{
			cal(s.find(make_pair(cost[ed], ed)), 1);
		}
		cout << A << ' ' << B << '\n';
	}
	return 0;
}