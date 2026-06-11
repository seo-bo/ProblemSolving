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
	vector<int> v(25);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[b] += a;
	}
	int ans = 0;
	for (int i = 0; i <= 23; ++i)
	{
		int temp = 0;
		for (int j = 0; j < 9; ++j)
		{
			temp += v[(i + j) % 24];
		}
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}
