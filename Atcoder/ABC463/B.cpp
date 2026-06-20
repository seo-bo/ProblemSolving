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
	char a;
	cin >> a;
	int p = a - 'A' + 1;
	vector<vector<char>>v(n + 1, vector<char>(6));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (v[i][p] == 'o')
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
