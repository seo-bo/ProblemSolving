#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>res(101);
	int l = 0, r = 0;
	cin >> l >> r;
	for (int i = l; i < r; ++i)
	{
		res[i]++;
	}
	cin >> l >> r;
	for (int i = l; i < r; ++i)
	{
		res[i] += 2;
	}
	int ans = 0;
	for (int i = 0; i <= 100; ++i)
	{
		ans += (res[i] == 3);
	}
	cout << ans;
	return 0;
}
