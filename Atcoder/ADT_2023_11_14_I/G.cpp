#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		v[a].push_back(i);
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		int st = lower_bound(v[c].begin(), v[c].end(), a) - v[c].begin();
		int ed = upper_bound(v[c].begin(), v[c].end(), b) - v[c].begin();
		cout << ed - st << '\n';
	}
	return 0;
}
