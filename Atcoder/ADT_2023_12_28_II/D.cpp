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
	vector<vector<int>>v(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		vector<int>temp(a);
		for (auto& j : temp)
		{
			cin >> j;
		}
		for (int j = 0; j < a; ++j)
		{
			for (int k = j + 1; k < a; ++k)
			{
				int pa = temp[j], pb = temp[k];
				v[pa][pb] = v[pb][pa] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			if (!v[i][j])
			{
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
