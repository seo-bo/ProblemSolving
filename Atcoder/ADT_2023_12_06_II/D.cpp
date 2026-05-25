#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>> v(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>> dir = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
	auto cal = [&](int x, int y, int d)
	{
		string temp;
		vector<pii> ans;
		while (1 <= x && x <= n && 1 <= y && y <= m && temp.size() < 5)
		{
			temp += v[x][y];
			ans.push_back(make_pair(x, y));
			x += dir[d][0];
			y += dir[d][1];
		}
		if (temp == "snuke")
		{
			for (auto &[a, b] : ans)
			{
				cout << a << ' ' << b << '\n';
			}
			exit(0);
		}
		reverse(temp.begin(), temp.end());
		if (temp == "snuke")
		{
			reverse(ans.begin(), ans.end());
			for (auto &[a, b] : ans)
			{
				cout << a << ' ' << b << '\n';
			}
			exit(0);
		}
	};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				cal(i, j, k);
			}
		}
	}
	return 0;
}
