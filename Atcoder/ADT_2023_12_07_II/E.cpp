#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, h = 0, k = 0;
	cin >> n >> m >> h >> k;
	string str, base = "RLUD";
	cin >> str;
	int x = 0, y = 0;
	vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	set<pii> s;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}
	for (auto &i : str)
	{
		--h;
		if (h < 0)
		{
			cout << "No";
			return 0;
		}
		int d = -1;
		for (int j = 0; j < 4; ++j)
		{
			if (base[j] == i)
			{
				d = j;
				break;
			}
		}
		x += dir[d][0], y += dir[d][1];
		if (h < k && s.find(make_pair(x, y)) != s.end())
		{
			h = k;
			s.erase(make_pair(x, y));
		}
	}
	cout << "Yes";
	return 0;
}
