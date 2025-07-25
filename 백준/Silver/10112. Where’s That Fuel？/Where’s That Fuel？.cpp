#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, p = 0, now = 0;
	cin >> n >> p;
	vector<pii>v;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0, b = 0;
		cin >> b >> a;
		if (i == p)
		{
			now = b;
			continue;
		}
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	int ans = 1;
	for (auto& [a, b] : v)
	{
		if (a > now)
		{
			break;
		}
		if (a <= b)
		{
			ans++;
			now += b - a;
		}
	}
	cout << now << '\n' << ans << '\n';
	return 0;
}