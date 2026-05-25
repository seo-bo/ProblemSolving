#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll op(ll a, ll b)
{
	return min(a, b);
}

ll e()
{
	return LLONG_MAX;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>> v(n + 1, vector<int>(3));
	vector<int> A = {0};
	for (int i = 1; i <= n; ++i)
	{
		for (auto &j : v[i])
		{
			cin >> j;
			A.push_back(j);
		}
		sort(v[i].rbegin(), v[i].rend());
	}
	sort(v.begin() + 1, v.end(), greater<>());
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	map<int, map<int, int>> B;
	int len = A.size() + 1;
	segtree<ll, op, e> seg(len + 2);
	for (int i = 1; i <= len; ++i)
	{
		seg.set(i, LLONG_MAX);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (auto &j : v[i])
		{
			j = lower_bound(A.begin(), A.end(), j) - A.begin();
		}
		ll a = v[i][1], b = v[i][2];
		B[a][b]++;
		if (B[a].begin()->first == b)
		{
			seg.set(a, b);
		}
	}
	for (int i = 1; i <= n;)
	{
		int idx = i;
		while (idx <= n && v[i][0] == v[idx][0])
		{
			idx++;
		}
		for (int j = i; j < idx; ++j)
		{
			ll a = v[j][1], b = v[j][2];
			if (--B[a][b] == 0)
			{
				B[a].erase(b);
				if (B[a].empty())
				{
					seg.set(a, LLONG_MAX);
					continue;
				}
			}
			seg.set(a, B[a].begin()->first);
		}
		for (int j = i; j < idx; ++j)
		{
			ll a = v[j][1], b = v[j][2];
			ll q = seg.prod(1, a);
			if (q < b)
			{
				cout << "Yes";
				return 0;
			}
		}
		i = idx;
	}
	cout << "No";
	return 0;
}
