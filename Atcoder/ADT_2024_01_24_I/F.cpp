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
	vector<ll>v;
	function<void(int, ll)> dfs = [&](int depth, ll sum)
		{
			if (depth == 3)
			{
				v.push_back(sum);
				return;
			}
			for (ll i = 1, j = 0; j <= 12; ++j, i = (i * 10) + 1)
			{
				dfs(depth + 1, sum + i);
			}
		};
	dfs(0, 0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v[n - 1];
	return 0;
}
