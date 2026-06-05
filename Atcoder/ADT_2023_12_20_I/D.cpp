#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	int p = a * 60 + b;
	auto cal = [&](int pivot)
	{
		int pa = pivot / 60, pb = pivot % 60;
		int A = 0, B = 0;
		if (pa >= 10)
		{
			A += pa / 10 * 10;
		}
		if (pb >= 10)
		{
			A += pb / 10;
		}
		B += pa % 10 * 10 + pb % 10;
		return (A < 24 && B < 60);
	};
	while (1)
	{
		if (cal(p))
		{
			cout << p / 60 << ' ' << p % 60;
			return 0;
		}
		p = (p + 1) % 1440;
	}
	return 0;
}
