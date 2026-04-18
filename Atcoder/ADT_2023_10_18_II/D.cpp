#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 2);
	for (int i = 2; i <= n; ++i)
	{
		cin >> v[i];
	}
	int x = n;
	for (int i = 0;; ++i)
	{
		if (x == 1)
		{
			cout << i;
			return 0;
		}
		x = v[x];
	}
	return 0;
}
