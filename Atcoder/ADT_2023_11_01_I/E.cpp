#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	ll temp = 1, ans = 0;
	for (ll i = len - 1, temp = 1; i >= 0; --i, temp *= 26)
	{
		int a = str[i] - 'A' + 1;
		ans += temp * a;
	}
	cout << ans;
	return 0;
}
