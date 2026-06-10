#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii> v;
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			char a;
			cin >> a;
			if (a == '#')
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	int len = v.size();
	vector<pii> p;
	auto cal = [&]
	{
		map<int, int> mm;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = i+1; j < 4; ++j)
			{
				auto [ax, ay] = p[i];
				auto [bx, by] = p[j];
				mm[(ax - bx) * (ax - bx) + (ay - by) * (ay - by)]++;
			}
		}
		if (mm.size() != 2)
		{
			return false;
		}
		auto it = mm.begin();
		if (it->second == 4 && next(it)->second == 2)
		{
			return true;
		}
		return false;
	};
	int ans = 0;
	function<void(int, int)> dfs = [&](int depth, int idx)
	{
		if (depth == 4)
		{
			if (cal())
			{
				ans++;
			}
			return;
		}
		if (idx == len)
		{
			return;
		}
		dfs(depth, idx + 1);
		p.push_back(v[idx]);
		dfs(depth + 1, idx + 1);
		p.pop_back();
	};
	dfs(0, 0);
	cout << ans;
	return 0;
}
