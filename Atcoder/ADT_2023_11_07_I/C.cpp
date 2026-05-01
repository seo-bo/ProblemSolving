#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<ll>>v(1001, vector<ll>(1001));
	v[1][1] = 1;
	cout << 1 << '\n';
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
