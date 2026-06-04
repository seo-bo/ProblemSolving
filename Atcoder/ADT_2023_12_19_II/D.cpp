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
	vector<int> v(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		v[i] = a;
	}
	int x = n, ans = 0;
	while (x != 1)
	{
		ans++;
		x = v[x];
	}
	cout << ans;
	return 0;
}
