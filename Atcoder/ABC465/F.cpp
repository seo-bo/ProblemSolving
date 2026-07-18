#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll prefix[1000001];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		prefix[a] += b;
	}
	for (int i = 1; i <= 100000; i *= 10)
	{
		for (int j = 0; j < 1000000; ++j)
		{
			int p = j / i % 10;
			if (p)
			{
				prefix[j] += prefix[j - i];
			}
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		vector<int>sx(6), ex(6);
		for (auto& i : sx)
		{
			char t;
			cin >> t;
			i = t - '0';
		}
		for (auto& i : ex)
		{
			char t;
			cin >> t;
			i = t - '0';
		}
		int flag = 1;
		for (int i = 0; i < 6; ++i)
		{
			if (sx[i] > ex[i])
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
		{
			cout << 0 << '\n';
			continue;
		}
		ll ans = 0;
		for (int i = 0; i < (1 << 6); ++i)
		{
			int bit = 0, temp = 0;
			for (int j = 0; j < 6; ++j)
			{
				if (i & (1 << j))
				{
					bit++;
					if (sx[j] == 0)
					{
						temp = -1;
						break;
					}
					temp = temp * 10 + sx[j] - 1;
				}
				else
				{
					temp = temp * 10 + ex[j];
				}
			}
			if (temp == -1)
			{
				continue;
			}
			if (bit % 2)
			{
				ans -= prefix[temp];
			}
			else
			{
				ans += prefix[temp];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
