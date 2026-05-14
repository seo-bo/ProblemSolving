#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 26; ++i)
	{
		int a = 0;
		cin >> a;
		cout << char(a - 1 + 'a');
	}
	return 0;
}
