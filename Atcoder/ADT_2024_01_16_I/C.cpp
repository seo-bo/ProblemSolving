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
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int a = 0;
			cin >> a;
			if (!a)
			{
				cout << '.';
				continue;
			}
			cout << char('A' + a - 1);
		}
		cout << '\n';
	}
	return 0;
}
