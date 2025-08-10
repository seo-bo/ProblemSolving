#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v = { 3,-1 };
		for (int i = 1; i <= n - 1; ++i)
		{
			cout << v[i % 2] << ' ';
		}
		if (n % 2)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << 2 << '\n';
		}
	}
	return 0;
}
