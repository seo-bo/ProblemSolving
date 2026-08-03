#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	int ans = 0;
	do
	{
		ans++;
	} while (next_permutation(str.begin(), str.end()));
	cout << ans;
	return 0;
}
