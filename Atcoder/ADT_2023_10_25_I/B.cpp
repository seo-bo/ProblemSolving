#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>>v = { {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>>dir = { {0,-1},{0,1} };
	int a = 0, b = 0;
	cin >> a >> b;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (v[i][j] == a)
			{
				for (int k = 0; k < 2; ++k)
				{
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && v[nx][ny] == b)
					{
						cout << "Yes";
						return 0;
					}
				}
			}
		}
	}
	cout << "No";
	return 0;
}
