#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	int p = a + b;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (p == temp)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
