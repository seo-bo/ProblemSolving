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
	vector<pii> pos(n);
	for (auto &[a, b] : pos)
	{
		cin >> a >> b;
	}
	string str;
	cin >> str;
	map<int, vector<pii>> mm;
	for (int i = 0; i < n; ++i)
	{
		auto [x, y] = pos[i];
		int p = (str[i] == 'L') ? 0 : 1;
		mm[y].push_back(make_pair(x, p));
	}
	for (auto &[a, b] : mm)
	{
		sort(b.begin(), b.end());
		int pre = 3;
		for (auto &i : b)
		{
			if (pre == 1 && !i.second)
			{
				cout << "Yes";
				return 0;
			}
			pre = i.second;
		}
	}
	cout << "No";
	return 0;
}
