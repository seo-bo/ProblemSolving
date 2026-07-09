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
	map<int, int> mm;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a] = i;
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (mm.find(a) == mm.end())
		{
			continue;
		}
		ans1 += (mm[a] == i);
		ans2 += (mm[a] != i);
	}
	cout << ans1 << '\n' << ans2;
	return 0;
}
