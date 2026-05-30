#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int m = 0;
	cin >> m;
	vector<vector<vector<int>>> v(3, vector<vector<int>>(10));
	for (int i = 0; i < 3; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			int p = str[j] - '0';
			v[i][p].push_back(j);
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i <= 9; ++i)
	{
		vector<int> per(3);
		iota(per.begin(), per.end(), 0);
		int flag = 1;
		for (auto &j : per)
		{
			if (v[j][i].empty())
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
		{
			continue;
		}
		do
		{
			int a = per[0], b = per[1], c = per[2], cnt = 0;
			int time = *v[a][i].begin();
			auto it = upper_bound(v[b][i].begin(), v[b][i].end(), time);
			if (it == v[b][i].end())
			{
				time = *v[b][i].begin();
				cnt++;
			}
			else
			{
				time = *it;
			}
			auto jt = upper_bound(v[c][i].begin(), v[c][i].end(), time);
			if (jt == v[c][i].end())
			{
				time = *v[c][i].begin();
				cnt++;
			}
			else
			{
				time = *jt;
			}
			ans = min(ans, cnt * m + time);
		} while (next_permutation(per.begin(), per.end()));
	}
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}
