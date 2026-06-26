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
	vector<int>ans((1 << n));
	function<void(int, int, int)> dfs = [&](int left, int right, int num)
		{
			int mid = (left + right) / 2;
			ans[mid] = num;
			if (num == 1)
			{
				return;
			}
			dfs(left, mid - 1, num - 1);
			dfs(mid + 1, right, num - 1);
		};
	dfs(1, (1 << n) - 1, n);
	for (int i = 1; i <= (1 << n) - 1; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
