#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>cost(m + 1), score(n + 1);
	iota(score.begin(), score.end(), 0);
	for (int i = 1; i <= m; ++i)
	{
		cin >> cost[i];
	}
	int maxi = 0;
	vector<vector<int>>nokori(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			if (str[j] == 'o')
			{
				score[i] += cost[j + 1];
			}
			else
			{
				nokori[i].push_back(cost[j + 1]);
			}
		}
		sort(nokori[i].rbegin(), nokori[i].rend());
		maxi = max(maxi, score[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		int now = score[i];
		for (int j = 0;; ++j)
		{
			if (now >= maxi)
			{
				cout << j << '\n';
				break;
			}
			now += nokori[i][j];
		}
	}
	return 0;
}
