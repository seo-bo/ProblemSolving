#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pii>A(n), B(m);
	for (auto& [a, b] : A)
	{
		cin >> b >> a;
	}
	for (auto& [a, b] : B)
	{
		cin >> b >> a;
	}
	int idx = 0, ans = 0;
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	map<int, int>mm;
	for (auto& [time, lim] : B)
	{
		while (idx < n && A[idx].first >= time)
		{
			mm[A[idx++].second]++;
		}
		auto it = mm.upper_bound(lim);
		if (it == mm.begin())
		{
			continue;
		}
		it = prev(it);
		ans++;
		if (--it->second == 0)
		{
			mm.erase(it);
		}
	}
	cout << ans;
	return 0;
}