#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int op(int a, int b)
{
	return max(a, b);
}

int e()
{
	return 0;
}

int mapping(int a, int b)
{
	return a + b;
}

int composition(int a, int b)
{
	return a + b;
}

int id()
{
	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0, w = 0;
	cin >> n >> d >> w;
	vector<pii> v(n);
	vector<int> x;
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
		x.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	lazy_segtree<int, op, e, int, mapping, composition, id> seg(222222);
	int idx = 0, jdx = 0, ans = 0;
	for (auto &i : x)
	{
		while (jdx < n && v[jdx].first < i)
		{
			int pre = max(1, v[jdx].second - w + 1);
			seg.apply(pre, v[jdx].second + 1, -1);
			jdx++;
		}
		while (idx < n && v[idx].first < i + d)
		{
			int pre = max(1, v[idx].second - w + 1);
			seg.apply(pre, v[idx].second + 1, 1);
			idx++;
		}
		ans = max(ans, seg.all_prod());
	}
	cout << ans;
	return 0;
}
