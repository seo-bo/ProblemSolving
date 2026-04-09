#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	string base = "UDRL";
	vector<vector<int>>dir = { {-1,0},{1,0},{0,1},{0,-1} };
	ll ans = 1;
	auto cal = [&](int a)
		{
			if (a <= n + 1)
			{
				return (ll)a * (a - 1) / 2;
			}
			return (ll)n * n - (ll)(n * 2 - a) * (n * 2 - a + 1) / 2;
		};
	int x = 1, y = 1;
	for (int i = 0; i < k; ++i)
	{
		char a;
		cin >> a;
		for (int j = 0; j < 4; ++j)
		{
			if (base[j] == a)
			{
				x += dir[j][0], y += dir[j][1];
				break;
			}
		}
		int pos = x + y, co = max(0, pos - n - 1);
		ans += cal(pos - 1) + ((pos % 2) ? x - co : y - co);
	}
	cout << ans;
	return 0;
}