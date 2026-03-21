#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pii>v;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int a = 0;
			cin >> a;
			v.push_back(make_pair(a, i));
		}
	}
	sort(v.begin(), v.end());
	vector<int>cnt(n + 1);
	int ans = INT_MAX;
	for (int left = 0, now = 0, right = 0; right < n * m; ++right)
	{
		auto [co, ve] = v[right];
		if (++cnt[ve] == 1)
		{
			now++;
		}
		while (cnt[v[left].second] - 1)
		{
			--cnt[v[left++].second];
		}
		if (now == n)
		{
			ans = min(ans, v[right].first - v[left].first);
		}
	}
	cout << ans;
	return 0;
}