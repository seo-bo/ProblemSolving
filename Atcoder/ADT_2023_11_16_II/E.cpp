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
	int ans = 0;
	for (int left = 0, right = 0; right < n; ++right)
	{
		if (str[right] == '-')
		{
			ans = max(ans, right - left);
			left = right + 1;
			continue;
		}
	}
	reverse(str.begin(), str.end());
	for (int left = 0, right = 0; right < n; ++right)
	{
		if (str[right] == '-')
		{
			ans = max(ans, right - left);
			left = right + 1;
			continue;
		}
	}
	cout << ((ans) ? ans : -1);
	return 0;
}
