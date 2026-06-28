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
	string str, base = "RLUD";
	cin >> str;
	set<pii>s;
	vector<vector<int>>dir = { {1,0},{-1,0},{0,1},{0,-1} };
	int x = 0, y = 0;
	s.insert(make_pair(x, y));
	for (auto& i : str)
	{
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
		if (s.find(make_pair(x, y)) != s.end())
		{
			cout << "Yes";
			return 0;
		}
		s.insert(make_pair(x, y));
	}
	cout << "No";
	return 0;
}
