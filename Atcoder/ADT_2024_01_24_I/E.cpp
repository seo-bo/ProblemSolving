#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	char pre = '-';
	int cnt = 0;
	map<char, int>mm;
	for (auto& i : str)
	{
		if (pre != i)
		{
			mm[pre] = max(mm[pre], cnt);
			pre = i;
			cnt = 1;
		}
		else
		{
			cnt++;
		}
	}
	mm[pre] = max(mm[pre], cnt);
	ll ans = 0;
	for (auto& [a, b] : mm)
	{
		ans += b;
	}
	cout << ans;
	return 0;
}
