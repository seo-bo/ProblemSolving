#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int base = 216;
	vector<vector<int>>v(3, vector<int>(3));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			int a = 0;
			cin >> a;
			if (a >= 4)
			{
				v[i][a - 4]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (i == j || j == k || i == k)
				{
					continue;
				}
				ans += v[0][i] * v[1][j] * v[2][k];
			}
		}
	}
	cout << fixed << setprecision(15) << (long double)ans / base;
	return 0;
}
