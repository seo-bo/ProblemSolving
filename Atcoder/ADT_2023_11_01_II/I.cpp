#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 하????????????????
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	function<ll(vector<ll>, int)> dfs = [&](vector<ll>pivot, int bit)
		{
			if (bit < 0)
			{
				return 0LL;
			}
			vector<ll>zero, one;
			for (auto& i : pivot)
			{
				if (i & (1LL << bit))
				{
					one.push_back(i);
				}
				else
				{
					zero.push_back(i);
				}
			}
			if (zero.empty())
			{
				return dfs(one, bit - 1);
			}
			if (one.empty())
			{
				return dfs(zero, bit - 1);
			}
			return (1LL << bit) + min(dfs(zero, bit - 1), dfs(one, bit - 1));
		};
	cout << dfs(v, 30);
	return 0;
}
