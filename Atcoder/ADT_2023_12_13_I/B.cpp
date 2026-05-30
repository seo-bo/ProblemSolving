#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, a = 0;
	cin >> n >> k >> a;
	a--;
	for (int i = 0; i < k; ++i)
	{
		a = (a + 1) % n;
	}
	cout << (a ? a : n);
	return 0;
}
