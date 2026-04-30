#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int mask = 0;
	for (int a = 1; a <= 1000; ++a)
	{
		for (int b = 1; b <= 1000; ++b)
		{
			int pivot = 3 * a + 3 * b + 4 * a * b;
			for (int i = 0; i < n; ++i)
			{
				if (v[i] == pivot)
				{
					mask |= (1 << i);
				}
			}
		}
	}
	cout << n - __builtin_popcount(mask);
	return 0;
}
