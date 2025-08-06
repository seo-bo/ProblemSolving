#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>mm(MAX + 1), ans(MAX + 1), v(n);
	for (auto& i : v)
	{
		cin >> i;
		mm[i]++;
	}
	for (ll i = 1; i <= 1000000; ++i)
	{
		if (!mm[i])
		{
			continue;
		}
		for (ll j = i; j <= 1000000; j += i)
		{
			if (!mm[j])
			{
				continue;
			}
			ans[j] += mm[i];
			if (i == j)
			{
				ans[j]--;
			}
		}
	}
	for (auto& i : v)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}