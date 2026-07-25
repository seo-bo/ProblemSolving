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
	vector<int>v(n), p;
	for (auto& i : v)
	{
		cin >> i;
		p.push_back(i);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	vector<int>ans(n + 1);
	int len = p.size();
	for (auto& i : v)
	{
		auto it = upper_bound(p.begin(), p.end(), i) - p.begin();
		ans[len - it]++;
	}
	for (int i = 0; i <= n - 1; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
