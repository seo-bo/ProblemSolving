#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	vector<vector<int>>v(n, vector<int>(n));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	int ax = 0, ay = 0, bx = n - 1, by = n - 1, ac = 0, bc = n - 1;
	while (a)
	{
		if (ax >= 0 && ax < n && ay >= 0 && ay < n)
		{
			v[ax][ay] = 1;
			a--;
		}
		ax++;
		ay--;
		if (ay == -1 || ax == n)
		{
			ac++;
			ax = 0, ay = ac;
		}

	}
	while (b)
	{
		if (bx >= 0 && bx < n && by >= 0 && by < n)
		{
			if (v[bx][by] == 1)
			{
				cout << -1;
				return 0;
			}
			for (int i = 0; i < 4; ++i)
			{
				int nx = bx + dir[i][0];
				int ny = by + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] == 1)
				{
					cout << -1;
					return 0;
				}
			}
			v[bx][by] = 2;
			b--;
		}
		bx--;
		by++;
		if (bx == -1 || by == n)
		{
			bc--;
			bx = n - 1, by = bc;
		}
	}
	cout << 1 << '\n';
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << j;
		}
		cout << '\n';
	}
	return 0;
}