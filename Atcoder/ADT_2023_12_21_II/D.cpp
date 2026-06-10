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
	for (int i = 1; i < n; ++i)
	{
		int ans = 0;
		for (int j = 0; i + j < n; ++j)
		{
			if (str[j] == str[j + i])
			{
				break;
			}
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
