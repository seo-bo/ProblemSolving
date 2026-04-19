#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>cnt(3 * n);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		cnt[i * 2] = cnt[i * 2 + 1] = cnt[a] + 1;
	}
	for (int i = 1; i <= 2 * n + 1; ++i)
	{
		cout << cnt[i] << '\n';
	}
	return 0;
}
