#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>mm;
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> b >> a;
		mm[b]++;
	}
	sort(v.begin(), v.end());
	int q = 0;
	cin >> q;
	vector<pii>query(q);
	for (int i = 0; i < q; ++i)
	{
		auto& [a, b] = query[i];
		cin >> a;
		b = i;
	}
	sort(query.begin(), query.end());
	vector<int>ans(q);
	int idx = 0;
	for (int i = 0; i < q; ++i)
	{
		auto [pivot, num] = query[i];
		while (idx < n && pivot >= v[idx].first)
		{
			int a = v[idx].second;
			if (--mm[a] == 0)
			{
				mm.erase(a);
			}
			idx++;
		}
		ans[num] = prev(mm.end())->first;
	}
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}
