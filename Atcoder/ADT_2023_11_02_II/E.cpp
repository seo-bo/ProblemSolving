#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v;
	function<void(int)> dfs = [&](int st)
		{
			if (v.size() == n)
			{
				for (auto& i : v)
				{
					cout << i << ' ';
				}
				cout << '\n';
				return;
			}
			if (st > m)
			{
				return;
			}
			for (int i = st; i <= m; ++i)
			{
				v.push_back(i);
				dfs(i + 1);
				v.pop_back();
			}
		};
	dfs(1);
	return 0;
}
