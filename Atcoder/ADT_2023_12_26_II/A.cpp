#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int s = 0, t = 0, x = 0;
	cin >> s >> t >> x;
	for (int i = s; i != t; i = (i + 1) % 24)
	{
		if (i == x)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
