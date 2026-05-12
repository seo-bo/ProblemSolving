#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

/*
1 (1)
1 2 1 (3)
1 2 1 3 1 2 1 (7)
1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 (15)
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int> ans((1 << n));
	function<void(int, int, int)> dfs = [&](int left, int right, int num)
	{
		if (left == right)
		{
			ans[left] = num;
			return;
		}
		int mid = (left + right) / 2;
		ans[mid] = num;
		dfs(left, mid - 1, num - 1);
		dfs(mid + 1, right, num - 1);
	};
	dfs(1, (1 << n) - 1, n);
	for (int i = 1; i < (1 << n); ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
