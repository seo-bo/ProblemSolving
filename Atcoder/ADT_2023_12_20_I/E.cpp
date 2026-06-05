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
	sort(str.begin(), str.end());
	ll ans = 0, len = str.size();
	do
	{
		for (int i = 1; i < len; ++i)
		{
			ll A = 0, B = 0;
			for (int j = 0; j < i; ++j)
			{
				A = A * 10 + str[j] - '0';
			}
			for (int j = i; j < len; ++j)
			{
				B = B * 10 + str[j] - '0';
			}
			ans = max(ans, A * B);
		}
	} while (next_permutation(str.begin(), str.end()));
	cout << ans;
	return 0;
}
