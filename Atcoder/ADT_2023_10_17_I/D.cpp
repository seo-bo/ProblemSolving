#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<bool>>visited(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		vector<int>v(a);
		for (auto& i : v)
		{
			cin >> i;
		}
		for (int j = 0; j < a; ++j)
		{
			for (int k = 0; k < a; ++k)
			{
				visited[v[j]][v[k]] = true;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (!visited[i][j])
			{
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
