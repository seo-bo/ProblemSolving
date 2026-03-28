#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	cout << format("1 {} {} ", 3 * n - 1, n + 1);
	vector<int>v = { 2 * n, 2, 2 * n + 1 }, d = { -1,1,1 };
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << v[j] << ' ';
			v[j] += d[j];
		}
	}
	cout << format("{} {} {}", n + 2, n, 3 * n);
	return 0;
}