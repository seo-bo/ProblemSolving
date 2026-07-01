#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	vector<vector<char>> v(n * a, vector<char>(b * n));
	for (int i = 0, p = 0; i < n; ++i, p ^= 1)
	{
		int temp = p;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < a; ++k)
			{
				for (int z = 0; z < b; ++z)
				{
					char pivot = ((temp) ? '#' : '.');
					v[i * a + k][j * b + z] = pivot;
				}
			}
			temp ^= 1;
		}
	}
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			cout << j;
		}
		cout << '\n';
	}
	return 0;
}
