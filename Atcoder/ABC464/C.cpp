#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	map<int, int>mm;
	vector<tp>v(n);
	for (auto& [a, b, c] : v)
	{
		cin >> b >> a >> c;
		mm[b]++;
	}
	sort(v.begin(), v.end());
	int idx = 0;
	for (int i = 1; i <= m; ++i)
	{
		while (idx < n && get<0>(v[idx]) <= i)
		{
			auto [a, b, c] = v[idx];
			if (--mm[b] == 0)
			{
				mm.erase(b);
			}
			mm[c]++;
			idx++;
		}
		cout << mm.size() << '\n';
	}
	return 0;
}
