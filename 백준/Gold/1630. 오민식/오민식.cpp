#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000
#define MOD 987654321

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>div(MAX + 1), cnt(MAX + 1);
	for (int i = 2; i <= MAX; ++i)
	{
		if (div[i])
		{
			continue;
		}
		for (int j = i; j <= MAX; j += i)
		{
			if (div[j])
			{
				continue;
			}
			div[j] = i;
		}
	}
	int n = 0;
	cin >> n;
	ll ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		int x = i;
		while (x > 1)
		{
			int d = div[x], c = 0;
			while (x % d == 0)
			{
				if (cnt[d] < ++c)
				{
					cnt[d] = c;
					ans = (ans * d) % MOD;
				}
				x /= d;
			}
		}
	}
	cout << ans;
	return 0;
}