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
	vector<vector<char>> v(n + 1, vector<char>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			int flag = 1;
			if (v[i][j] == 'W')
			{
				flag &= (v[j][i] == 'L');
			}
			if (v[i][j] == 'L')
			{
				flag &= (v[j][i] == 'W');
			}
			if (v[i][j] == 'D')
			{
				flag &= (v[j][i] == 'D');
			}
			if (!flag)
			{
				cout << "incorrect";
				return 0;
			}
		}
	}
	cout << "correct";
	return 0;
}
