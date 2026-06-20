#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, vector<int>>mm;
	int n = 0, q = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a].push_back(i);
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (b > mm[a].size())
		{
			cout << -1 << '\n';
			continue;
		}
		cout << mm[a][b - 1] << '\n';
	}
	return 0;
}
