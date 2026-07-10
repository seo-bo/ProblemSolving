#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, r = 0, c = 0, ans = 0;
	cin >> h >> w >> r >> c;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < 4; ++i)
	{
		int nx = r + dir[i][0];
		int ny = c + dir[i][1];
		ans += (nx >= 1 && nx <= h && ny >= 1 && ny <= w);
	}
	cout << ans;
	return 0;
}
