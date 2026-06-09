#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0;
	cin >> n >> x;
	vector<pii> v(n);
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
	}
	vector<bool> dp(x + 1);
	dp[0] = true;
	for (auto &[co, a] : v)
	{
		for (int i = 1; i <= a; ++i)
		{
			vector<bool> temp = dp;
			for (int j = x; j >= co; --j)
			{
				if (!dp[j - co])
				{
					continue;
				}
				temp[j] = true;
			}
			dp = move(temp);
		}
	}
	cout << ((dp[x]) ? "Yes" : "No");
	return 0;
}
