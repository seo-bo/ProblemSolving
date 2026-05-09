#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n + 1,vector<int>(1));
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			v[i].push_back(b);
		}
	}
	int x = 0, y = 0;
	cin >> x >> y;
	cout << v[x][y];
	return 0;
}
