#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	set<int>odd, even;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a % 2)
		{
			odd.insert(a);
		}
		else
		{
			even.insert(a);
		}
	}
	int ans = -1;
	if (odd.size() >= 2)
	{
		auto it = prev(odd.end());
		ans = max(ans, *it + *prev(it));
	}
	if (even.size() >= 2)
	{
		auto it = prev(even.end());
		ans = max(ans, *it + *prev(it));
	}
	cout << ans;
	return 0;
}
