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
	vector<vector<char>>v(n + 1, vector<char>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
			{
				continue;
			}
			if ((v[i][j] == 'W' && v[j][i] != 'L') || (v[i][j] == 'L' && v[j][i] != 'W') || (v[i][j] == 'D' && v[j][i] != 'D'))
			{
				cout << "incorrect";
				return 0;
			}
		}
	}
	cout << "correct";
	return 0;
}
