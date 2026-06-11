#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<ll, int> mm;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a]++;
	}
	int ans = 0;
	for (auto &[a, b] : mm)
	{
		ans += b / 2;
	}
	cout << ans;
	return 0;
}
