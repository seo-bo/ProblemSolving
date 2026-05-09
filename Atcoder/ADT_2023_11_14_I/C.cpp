#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<string, int> mm;
	int maxi = 0, n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		maxi = max(maxi, ++mm[str]);
	}
	for (auto &[a, b] : mm)
	{
		if (maxi == b)
		{
			cout << a;
			return 0;
		}
	}
	return 0;
}
