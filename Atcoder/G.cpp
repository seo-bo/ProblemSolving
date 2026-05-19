#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		b -= a * 2;
		if (b < 0)
		{
			cout << "No\n";
			continue;
		}
		int f = 1;
		for (int i = 0; i < 60; ++i)
		{
			if ((a & (1LL << i)) && (b & (1LL << i)))
			{
				f = 0;
				break;
			}
		}
		cout << ((f) ? "Yes" : "No") << '\n';
	}
	return 0;
}
