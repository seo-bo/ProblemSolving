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
	vector<vector<int>>g1(n + 1, vector<int>(n + 1)), g2(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		g1[a][b] = g1[b][a] = 1;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		g2[a][b] = g2[b][a] = 1;
	}
	vector<int>per(n);
	iota(per.begin(), per.end(), 1);
	do
	{
		int flag = 1;
		for (int i = 0; i < n && flag; ++i)
		{
			for (int j = i; j < n && flag; ++j)
			{
				if (g1[i + 1][j + 1] != g2[per[i]][per[j]])
				{
					flag = 0;
				}
			}
		}
		if (flag)
		{
			cout << "Yes";
			return 0;
		}
	} while (next_permutation(per.begin(), per.end()));
	cout << "No";
	return 0;
}
