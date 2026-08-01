#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	map<pii, int>mm;
	vector<int>degree(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		degree[a]++, degree[b]++;
		mm[make_pair(a, b)]++;
	}
	vector<ll>cnt(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cnt[degree[i]]++;
	}
	ll ans = 0;
	for (int i = 0; i <= m / 2; ++i)
	{
		int pivot = m - i;
		if (i == pivot)
		{
			ans += cnt[i] * (cnt[i] - 1) / 2;
		}
		else
		{
			ans += cnt[i] * cnt[pivot];
		}
	}
	for (auto& [a, b] : mm)
	{
		auto [x, y] = a;
		if (degree[x] + degree[y] == m)
		{
			ans--;
		}
		if (degree[x] + degree[y] - b == m)
		{
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
