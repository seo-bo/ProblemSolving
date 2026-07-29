#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<ll>>v(31, vector<ll>(31, 1));
	for (int i = 3; i <= 30; ++i)
	{
		for (int j = 2; j <= i - 1; ++j)
		{
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
		}
	}
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
