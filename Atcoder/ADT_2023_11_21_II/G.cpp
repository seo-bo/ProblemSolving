#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	map<ll, ll> mm;
	ll mask = 0, ans = 0;
	mm[0]++;
	for (auto &i : str)
	{
		mask ^= (1LL << int(i - '0'));
		ans += mm[mask]++;
	}
	cout << ans;
	return 0;
}
