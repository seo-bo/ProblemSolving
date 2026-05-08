#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> A(n + 1, vector<int>(n + 1)), B(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		A[a][b] = A[b][a] = 1;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		B[a][b] = B[b][a] = 1;
	}
	vector<int> per(n);
	iota(per.begin(), per.end(), 1);
	do
	{
		int flag = 1;
		for (int i = 1; i <= n && flag; ++i)
		{
			for (int j = 1; j <= n && flag; ++j)
			{
				if (A[i][j] != B[per[i - 1]][per[j - 1]])
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
