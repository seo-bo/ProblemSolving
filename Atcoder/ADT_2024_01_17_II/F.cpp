#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int r = 0, c = 0;
	auto cal = [&]
		{
			int sx = n + 1, sy = n + 1, ex = 0, ey = 0;
			vector<pii>pos;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					char a;
					cin >> a;
					if (a == '#')
					{
						pos.push_back(make_pair(i, j));
						sx = min(sx, i), sy = min(sy, j);
						ex = max(ex, i), ey = max(ey, j);
					}
				}
			}
			r = ex - sx + 1, c = ey - sy + 1;
			for (auto& [a, b] : pos)
			{
				a -= sx, b -= sy;
			}
			sort(pos.begin(), pos.end());
			return pos;
		};
	vector<pii>A = cal(), B = cal();
	for (int i = 0; i < 4; ++i)
	{
		for (auto& [a, b] : B)
		{
			int na = b, nb = r - 1 - a;
			a = na, b = nb;
		}
		swap(r, c);
		sort(B.begin(), B.end());
		if (A == B)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
