#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, vector<pii>> mm;
	int n = 0, t = 0;
	cin >> n >> t;
	vector<int> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[v[i - 1]].push_back(make_pair(a, i));
	}
	auto it = mm.find(t);
	if (it == mm.end())
	{
		it = mm.find(v[0]);
	}
	sort(it->second.rbegin(), it->second.rend());
	cout << it->second.front().second;
	return 0;
}
