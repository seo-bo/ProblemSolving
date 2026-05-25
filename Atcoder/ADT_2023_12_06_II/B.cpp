#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, x = 0, t = 0, d = 0;
	cin >> n >> m >> x >> t >> d;
	for (int i = x; i > m; --i)
	{
		t -= d;
	}
	cout << t;
	return 0;
}
