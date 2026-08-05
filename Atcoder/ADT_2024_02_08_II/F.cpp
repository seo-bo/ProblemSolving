#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<vector<int>>>pos(4, vector<vector<int>>(10));
	for (int i = 1; i <= 3; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			int p = str[j] - '0';
			pos[i][p].push_back(j);
		}
	}
	vector<int>per(3);
	iota(per.begin(), per.end(), 1);
	int ans = INT_MAX;
	do
	{
		int temp = INT_MAX;
		for (int i = 0; i <= 9; ++i)
		{
			int time = 0;
			for (int j = 0; j < 3; ++j)
			{
				auto& v = pos[per[j]][i];
				if (v.empty())
				{
					time = INT_MAX;
					break;
				}
				int now = time % n;
				auto it = lower_bound(v.begin(), v.end(), now);
				if (it != v.end())
				{
					time += *it - now + 1;
					continue;
				}
				time += *v.begin() + n - now + 1;
			}
			temp = min(temp, time);
		}
		ans = min(ans, temp);
	} while (next_permutation(per.begin(), per.end()));
	cout << ((ans == INT_MAX) ? -1 : ans - 1);
	return 0;
}
