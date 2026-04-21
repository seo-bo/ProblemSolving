#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, vector<int>>mm;
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a].push_back(i);
	}
	while (m--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (mm.find(a) == mm.end() || mm[a].size() < b)
		{
			cout << -1 << '\n';
			continue;
		}
		cout << mm[a][b - 1] << '\n';
	}
	return 0;
}
