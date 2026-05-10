#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	map<int, int> mm;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a]++;
	}
	for (int i = 1; i <= m; ++i)
	{
		int a = 0;
		cin >> a;
		if (--mm[a] == -1)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
