#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(9);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<int>per(9);
	iota(per.begin(), per.end(), 0);
	int res = 0, tot = 0;
	auto sv = [&](vector<vector<int>>& w, int idx, int co)
		{
			if (w[idx].size() == 1 && w[idx].back() == co)
			{
				res++;
				return true;
			}
			w[idx].push_back(co);
			return false;
		};
	do
	{
		vector<int>d = { 0,4,8,2,4,6 };
		vector<vector<int>>row(3), col(3), diag(2);
		int flag = 1;
		for (int i = 0; i < 9 && flag; ++i)
		{
			int t = per[i], x = t / 3, y = t % 3;
			if (sv(row, x, v[t]))
			{
				break;
			}
			if (sv(col, y, v[t]))
			{
				break;
			}
			vector<int>idx;
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					if (d[j * 3 + k] == t)
					{
						idx.push_back(j);
						break;
					}
				}
			}
			if (idx.empty())
			{
				continue;
			}
			for (auto& j : idx)
			{
				if (sv(diag, j, v[t]))
				{
					flag = 0;
					break;
				}
			}
		}
		tot++;
	} while (next_permutation(per.begin(), per.end()));
	cout << fixed << setprecision(15) << (double)(tot - res) / tot;
	return 0;
}

