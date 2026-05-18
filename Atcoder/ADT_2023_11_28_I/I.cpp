#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<pii, int> mm;
	vector<pii> v;
	set<int> dou;
	for (int i = 1, cnt = 1; i <= (1 << 11); i <<= 1)
	{
		dou.insert(i);
		for (int j = 1; j + i - 1 <= n; ++j)
		{
			int left = j, right = j + i - 1;
			pii res = make_pair(left, right);
			v.push_back(res);
			mm[res] = cnt++;
		}
	}
	cout << v.size() << endl;
	for (auto &[a, b] : v)
	{
		cout << a << ' ' << b << endl;
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int l = 0, r = 0;
		cin >> l >> r;
		if (l == r)
		{
			int ans = mm[make_pair(l, r)];
			cout << ans << ' ' << ans << endl;
			continue;
		}
		int term = r - l + 1;
		int a = term / 2, b = term - term / 2;
		a = *dou.lower_bound(a), b = *dou.lower_bound(b);
		int ans1 = mm[make_pair(l, l + a - 1)], ans2 = mm[make_pair(r - b + 1, r)];
		cout << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}
