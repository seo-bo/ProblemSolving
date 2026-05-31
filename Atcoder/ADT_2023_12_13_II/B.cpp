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
	int ans = 0;
	for (auto &i : str)
	{
		ans += 1 + (i == 'w');
	}
	cout << ans;
	return 0;
}
