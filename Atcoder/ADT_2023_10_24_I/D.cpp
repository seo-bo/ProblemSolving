#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<char>>v(10, vector<char>(10));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int a = 0, b = 10;
	for (int i = 0; i < 10; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < 10; ++j)
		{
			cnt += (v[i][j] == '#');
		}
		if (cnt && !a)
		{
			a = i + 1;
		}
		if (!cnt && a && b == 10)
		{
			b = i;
		}
	}
	int c = 0, d = 10;
	for (int i = 0; i < 10; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < 10; ++j)
		{
			cnt += (v[j][i] == '#');
		}
		if (cnt && !c)
		{
			c = i + 1;
		}
		if (!cnt && c && d == 10)
		{
			d = i;
		}
	}
	cout << a << ' ' << b << '\n' << c << ' ' << d;
	return 0;
}
