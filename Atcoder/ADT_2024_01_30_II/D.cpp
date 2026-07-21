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
	vector<vector<int>>v(101, vector<int>(101));
	while (n--)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		for (int i = a; i < b; ++i)
		{
			for (int j = c; j < d; ++j)
			{
				v[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			ans += j;
		}
	}
	cout << ans;
	return 0;
}
