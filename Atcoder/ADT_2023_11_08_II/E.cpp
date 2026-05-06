#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int ans = INT_MAX;
	for (int i = 0; i < (1 << n); ++i)
	{
		int res = 0, temp = v[0];
		for (int j = 1; j < n; ++j)
		{
			if (((i & (1 << (j - 1))) != 0) != ((i & (1 << j)) != 0))
			{
				res ^= temp;
				temp = v[j];
			}
			else
			{
				temp |= v[j];
			}
		}
		ans = min(ans, res ^ temp);
	}
	cout << ans;
	return 0;
}
