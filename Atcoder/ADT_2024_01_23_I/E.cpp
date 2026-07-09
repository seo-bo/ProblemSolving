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
	int len = str.size();
	ll ans = 0;
	do
	{
		for (int i = 1; i < len; ++i)
		{
			string A, B;
			for (int j = 0; j < i; ++j)
			{
				A += str[j];
			}
			for (int j = i; j < len; ++j)
			{
				B += str[j];
			}
			ans = max(ans, stoll(A) * stoll(B));
		}
	} while (next_permutation(str.begin(), str.end()));
	cout << ans;
	return 0;
}
