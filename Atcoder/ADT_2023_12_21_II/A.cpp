#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int> x, y;
	for (int i = 0; i < 3; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		x[a]++;
		y[b]++;
	}
	for (auto &[a, b] : x)
	{
		if (b == 1)
		{
			cout << a << ' ';
		}
	}
	for (auto &[a, b] : y)
	{
		if (b == 1)
		{
			cout << a << ' ';
		}
	}
	return 0;
}
