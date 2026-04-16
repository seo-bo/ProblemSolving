#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	int x = n * a, y = n * b;
	vector<vector<char>>v(n * a + 1, vector<char>(n * b + 1));
	string base = ".#";
	for (int i = 1, idx = 0; i <= x; i += a, idx ^= 1)
	{
		int p = idx;
		for (int j = 1; j <= y; j += b)
		{
			for (int nx = i; nx < i + a; ++nx)
			{
				for (int ny = j; ny < j + b; ++ny)
				{
					v[nx][ny] = base[p];
				}
			}
			p ^= 1;
		}
	}
	for (int i = 1; i <= x; ++i)
	{
		for (int j = 1; j <= y; ++j)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}
	return 0;
}
