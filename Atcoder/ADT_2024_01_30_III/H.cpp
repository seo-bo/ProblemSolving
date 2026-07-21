#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, l = 0;
	cin >> n >> m >> l;
	vector<int>A(n + 1);
	vector<pii>B(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		auto& [a, b] = B[i];
		cin >> a;
		b = i;
	}
	sort(B.begin() + 1, B.end());
	set<pii>s;
	for (int i = 0; i < l; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}
	int ans = INT_MIN;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			auto [co, num] = B[j];
			if (s.find(make_pair(i, num)) == s.end())
			{
				ans = max(ans, A[i] + co);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
