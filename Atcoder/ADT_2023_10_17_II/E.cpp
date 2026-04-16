#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>base(n + 1, vector<char>(m + 1));
	vector<string>A(m + 1), B(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> base[i][j];
		}
	}
	for (int j = 1; j <= m; ++j)
	{
		for (int i = 1; i <= n; ++i)
		{
			A[j] += base[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> base[i][j];
		}
	}
	for (int j = 1; j <= m; ++j)
	{
		for (int i = 1; i <= n; ++i)
		{
			B[j] += base[i][j];
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	cout << ((A == B) ? "Yes" : "No");
	return 0;
}
