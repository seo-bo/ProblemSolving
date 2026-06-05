#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int pre = 0;
	for (int i = 1; i <= 8; ++i)
	{
		int a = 0;
		cin >> a;
		if (a < pre || a < 100 || a > 675 || a % 25)
		{
			cout << "No";
			return 0;
		}
		pre = a;
	}
	cout << "Yes";
	return 0;
}
