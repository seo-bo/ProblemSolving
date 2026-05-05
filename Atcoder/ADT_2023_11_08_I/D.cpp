#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, w = 0;
	cin >> n >> w;
	vector<int> A(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	set<int> s;
	function<void(int, int, int)> dfs = [&](int depth, int sum, int idx)
	{
		if (sum <= w)
		{
			s.insert(sum);
		}
		if (depth == 3)
		{
			return;
		}
		for (int i = idx; i <= n; ++i)
		{
			if (sum + A[i] > w)
			{
				continue;
			}
			dfs(depth + 1, sum + A[i], i + 1);
		}
	};
	dfs(0, 0, 1);
	s.erase(0);
	cout << s.size();
	return 0;
}
