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
	vector<vector<int>> A(n + 1, vector<int>(n + 1));
	vector<vector<int>> B(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> B[i][j];
		}
	}
	auto cal = [&]
	{
		vector<vector<int>> nxt(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				nxt[n + 1 - j][i] = A[i][j];
			}
		}
		A = move(nxt);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (A[i][j])
				{
					if (!B[i][j])
					{
						return false;
					}
				}
			}
		}
		return true;
	};
	for (int i = 0; i < 4; ++i)
	{
		if (cal())
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
