#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int cnt = 0;
	vector<pii> v;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			char a;
			cin >> a;
			cnt += (a == '#');
			if (a == '#')
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	if (cnt == 2)
	{
		auto [ax, ay] = v[0];
		auto [bx, by] = v[1];
		cout << (((abs(ax - bx) + abs(ay - by)) == 2) ? "No" : "Yes");
		return 0;
	}
	cout << "Yes";
	return 0;
}
