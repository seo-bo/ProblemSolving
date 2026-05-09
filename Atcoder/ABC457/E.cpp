#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>start(n + 1), end(n + 1);
	for (ll i = 1; i <= m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		start[a].push_back(b);
		end[b].push_back(a);
	}
	for (ll i = 1; i <= n; ++i)
	{
		sort(start[i].begin(), start[i].end());
		sort(end[i].begin(), end[i].end());
	}
	vector<vector<ll>>v(n + 2, vector<ll>(2, LLONG_MAX));
	for (ll i = n; i >= 1; --i)
	{
		v[i] = v[i + 1];
		for (auto& j : start[i])
		{
			if (j <= v[i][0])
			{
				v[i][1] = v[i][0], v[i][0] = j;
			}
			else if (j <= v[i][1])
			{
				v[i][1] = j;
			}
		}
	}
	ll q = 0;
	cin >> q;
	while (q--) // it -> right / jt -> left
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		auto it = upper_bound(start[a].begin(), start[a].end(), b);
		auto jt = lower_bound(end[b].begin(), end[b].end(), a);
		if (it == start[a].begin() || jt == end[b].end())
		{
			cout << "No" << '\n';
			continue;
		}
		it = prev(it);
		if (*it + 1 < *jt) // right < left
		{
			cout << "No" << '\n';
			continue;
		}
		if (*it == b && *jt == a) // left (a,b) / right (a,b), 1? 2?
		{
			cout << ((v[a][1] <= b) ? "Yes" : "No") << '\n';
			continue;
		}
		cout << "Yes" << '\n';
	}
	return 0;
}
