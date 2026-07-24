#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>base;
	for (int i = 1; i <= n; i <<= 1)
	{
		base.push_back(i - 1);
	}
	vector<map<int, int>>res(n + 1);
	int cnt = 0;
	for (auto& p : base)
	{
		for (int i = 1; i + p <= n; ++i)
		{
			res[p][i] = ++cnt;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i <= n; ++i)
	{
		if (res[i].empty())
		{
			continue;
		}
		for (auto& [a, b] : res[i])
		{
			cout << a << ' ' << a + i << endl;
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int l = 0, r = 0;
		cin >> l >> r;
		int p = (r - l) / 2;
		auto it = lower_bound(base.begin(), base.end(), p);
		p = *it;
		cout << res[p][l] << ' ' << res[p][r - p] << endl;
	}
	return 0;
}
