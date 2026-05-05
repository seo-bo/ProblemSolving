#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int> mm;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n * 4 - 1; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a]++;
	}
	for (auto &[a, b] : mm)
	{
		if (b == 3)
		{
			cout << a;
			return 0;
		}
	}
	return 0;
}
