#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int> A, B;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		A[a] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		B[a] = i;
	}
	int ans1 = 0, ans2 = 0;
	for (auto &[a, b] : A)
	{
		if (B.find(a) != B.end())
		{
			ans1 += (b == B[a]);
			ans2 += (b != B[a]);
		}
	}
	cout << ans1 << '\n' << ans2;
	return 0;
}
