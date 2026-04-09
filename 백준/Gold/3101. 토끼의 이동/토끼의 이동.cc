#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	string str, base = "UDRL";
	cin >> str;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,1},{0,-1} };
	vector<ll>sum(2 * n + 1);
	ll ans = 1;
	for (int i = 2, p = 1; i <= 2 * n; ++i)
	{
		sum[i] += sum[i - 1] + p;
		(i >= n + 1) ? p-- : p++;
	}
	int x = 1, y = 1;
	for (auto& i : str)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (base[j] == i)
			{
				x += dir[j][0];
				y += dir[j][1];
				break;
			}
		}
		int pos = x + y, co = max(0, pos - n - 1);
		ans += sum[pos - 1] + ((pos % 2) ? x - co : y - co);
	}
	cout << ans;
	return 0;
}