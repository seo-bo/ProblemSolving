#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<pii>v(n + 1);
	vector<int>color(n + 1);
	vector<map<int, int>>mm(n + 1);
	for (int i = 1; i <= n - 1; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a >> b >> color[i];
		mm[a][0]++, mm[b][0]++;
	}
	int ans = 1;
	auto cal = [&](int t, int co, int ori = 0)
		{
			auto [v1, v2] = v[t];
			int ac = 0, bc = 0;
			if (co == ori)
			{
				return;
			}
			for (auto& i : { v1,v2 })
			{
				if (--mm[i][ori] == 0)
				{
					mm[i].erase(ori);
				}
				ac += (mm[i].find(ori) == mm[i].end());
				bc += (mm[i].find(co) == mm[i].end());
				mm[i][co]++;
			}
			ans += (ac == 0) - (ac == 2) - (bc == 0) + (bc == 2);
			color[t] = co;
		};
	for (int i = 1; i <= n - 1; ++i)
	{
		cal(i, color[i]);
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cal(a, b, color[a]);
		cout << ans << '\n';
	}
	return 0;
}