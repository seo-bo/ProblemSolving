#include <bits/stdc++.h>
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
		if (n == 0)
		{
			cout << "1\n2\n";
			continue;
		}
		int a = 1 << 30;
		cout << 2 << '\n' << a << ' ' << a + 1 << '\n';
	}
	return 0;
}