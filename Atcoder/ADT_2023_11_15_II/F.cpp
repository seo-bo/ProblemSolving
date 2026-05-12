#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

/*
1 2 3 4 5 8
5 8 2 2 1 2

1 2 3 4
1 3 2 4

1 2 3 4 5 6 7 8 9 10
5 8 2 2 1 6 7 2 9 10

*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll cnt = 0;
	map<pii, int> mm;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (i == a)
		{
			cnt++;
			continue;
		}
		int A = i, B = a;
		if (A > B)
		{
			swap(A, B);
		}
		mm[make_pair(A, B)]++;
	}
	ll ans = cnt * (cnt - 1) / 2;
	for (auto &[a, b] : mm)
	{
		ans += (b == 2);
	}
	cout << ans;
	return 0;
}
