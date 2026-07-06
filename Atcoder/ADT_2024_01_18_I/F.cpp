#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>> v(10, vector<int>(10));
	vector<set<int>> row(10), col(10), three(10);
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			row[i].insert(v[i][j]);
			col[j].insert(v[i][j]);
		}
	}
	int cnt = 1;
	auto cal = [&](int x, int y)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				three[cnt].insert(v[x + i][y + j]);
			}
		}
		cnt++;
	};
	for (int i = 1; i <= 7; i += 3)
	{
		for (int j = 1; j <= 7; j += 3)
		{
			cal(i, j);
		}
	}
	int tot = 0;
	for (int i = 1; i <= 9; ++i)
	{
		tot += row[i].size();
		tot += col[i].size();
		tot += three[i].size();
	}
	cout << ((tot == 243) ? "Yes" : "No");
	return 0;
}
