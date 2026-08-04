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
	while (!str.empty())
	{
		ans++;
		int a = str.back() - '0';
		str.pop_back();
		if (a == 0 && !str.empty() && str.back() == '0')
		{
			str.pop_back();
		}
	}
	cout << ans;
	return 0;
}
