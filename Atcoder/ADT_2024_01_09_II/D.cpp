#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pii>pos;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char a;
			cin >> a;
			if (a == 'o')
			{
				pos.push_back(make_pair(i, j));
			}
		}
	}
	auto [sx, sy] = pos[0];
	auto [ex, ey] = pos[1];
	cout << abs(sx - ex) + abs(sy - ey);
	return 0;
}
