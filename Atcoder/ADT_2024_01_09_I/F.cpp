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
	int k = 0, cnt = 1;
	cin >> k;
	sort(str.begin(), str.end());
	do
	{
		if (cnt == k)
		{
			cout << str;
			return 0;
		}
		cnt++;
	} while (next_permutation(str.begin(), str.end()));
	return 0;
}
