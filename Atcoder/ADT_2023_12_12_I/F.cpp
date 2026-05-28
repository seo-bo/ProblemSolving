#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int h = 0, w = 0;
	auto cal = [&]
	{
		vector<vector<char>> v(n + 1, vector<char>(n + 1));
		vector<pii> pos;
		int ax = INT_MAX, ay = INT_MAX, bx = 0, by = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cin >> v[i][j];
				if (v[i][j] == '#')
				{
					ax = min(ax, i);
					ay = min(ay, j);
					bx = max(bx, i);
					by = max(by, j);
				}
			}
		}
		for (int i = ax, p = 0; i <= bx; ++i, ++p)
		{
			for (int j = ay, z = 0; j <= by; ++z, ++j)
			{
				if (v[i][j] == '#')
				{
					pos.push_back(make_pair(p, z));
				}
			}
		}
		if (!h)
		{
			h = bx - ax + 1, w = by - ay + 1;
		}
		return pos;
	};

	vector<pii> A = cal(), B = cal();
	auto rot = [&]
	{
		for (auto &[a, b] : A)
		{
			int na = b, nb = h - 1 - a;
			a = na;
			b = nb;
		}
		sort(A.begin(), A.end());
		swap(w, h);
	};
	for (int i = 0; i < 5; ++i)
	{
		if (A == B)
		{
			cout << "Yes";
			return 0;
		}
		rot();
	}
	cout << "No";
	return 0;
}
