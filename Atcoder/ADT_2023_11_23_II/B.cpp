#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	int ans = 0;
	while (m--)
	{
		int a = 0;
		cin >> a;
		ans += v[a];
	}
	cout << ans;
	return 0;
}
