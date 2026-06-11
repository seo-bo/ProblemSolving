#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	vector<int> v(1001);
	for (int i = a; i <= b - 1; ++i)
	{
		v[i]++;
	}
	for (int i = c; i <= d - 1; ++i)
	{
		v[i] += 2;
	}
	int ans = 0;
	for (int i = 0; i <= 1000; ++i)
	{
		ans += (v[i] == 3);
	}
	cout << ans;
	return 0;
}
