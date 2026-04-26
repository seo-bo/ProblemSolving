#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<vector<int>>dir = { {1,0},{0,-1},{-1,0},{0,1} };
	int d = 0, x = 0, y = 0;
	for (auto& i : str)
	{
		if (i == 'S')
		{
			x += dir[d][0], y += dir[d][1];
			continue;
		}
		d = (d + 1) % 4;
	}
	cout << x << ' ' << y;
	return 0;
}
