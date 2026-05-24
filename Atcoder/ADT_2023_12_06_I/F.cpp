#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> A(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> A[i][j];
		}
	}
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<int>> B(h + 1, vector<int>(w + 1));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> B[i][j];
		}
	}
	vector<int> pos = {0};
	auto cal = [&]
	{
		int idx = 1;
		for (int i = 1; i <= n && idx <= h; ++i)
		{
			int flag = 1;
			for (int j = 1; j <= w; ++j)
			{
				if (A[i][pos[j]] == B[idx][j])
				{
					continue;
				}
				flag = 0;
				break;
			}
			idx += flag;
		}
		return (idx > h);
	};
	function<bool(int, int, int)> dfs = [&](int row, int depth, int idx)
	{
		if (depth > w)
		{
			return cal();
		}
		for (int i = idx; i <= m; ++i)
		{
			if (A[row][i] == B[1][depth])
			{
				pos.push_back(i);
				if (dfs(row, depth + 1, i + 1))
				{
					return true;
				}
				pos.pop_back();
			}
		}
		return false;
	};
	for (int i = 1; i <= n; ++i)
	{
		if (dfs(i, 1, 1))
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
