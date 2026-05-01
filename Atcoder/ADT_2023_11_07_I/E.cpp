#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int ans = 0;
	map<int, int>mm;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		ans += (++mm[a] % 2 == 0);
	}
	cout << ans;
	return 0;
}
