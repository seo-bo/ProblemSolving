#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, s = 0;
	cin >> n >> s;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	cout << str;
	return 0;
}