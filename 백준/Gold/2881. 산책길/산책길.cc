#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<map<int, vector<int>>>pos(2);
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		pos[0][a].push_back(b);
		pos[1][b].push_back(a);
	}
	for (auto& i : pos)
	{
		for (auto& [a, b] : i)
		{
			sort(b.begin(), b.end());
		}
	}
	auto cal = [&](int t, int idx, int st, int ed)
		{
			auto& v = pos[t][idx];
			return upper_bound(v.begin(), v.end(), ed) - lower_bound(v.begin(), v.end(), st);
		};
	int q = 0;
	cin >> q;
	vector<vector<int>>per = { {0,0,1,3},{0,2,1,3},{1,1,0,2},{1,3,0,2} };
	while (q--)
	{
		vector<int>p(4);
		for (auto& i : p)
		{
			cin >> i;
		}
		int res = 0;
		for (auto& i : per)
		{
			res += cal(i[0], p[i[1]], p[i[2]], p[i[3]]);
		}
		for (int i = 0; i < 4; i += 2)
		{
			for (int j = 1; j < 4; j += 2)
			{
				auto& v = pos[0][p[i]];
				res -= binary_search(v.begin(), v.end(), p[j]);
			}
		}
		cout << res << '\n';
	}
	return 0;
}