#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0;
	cin >> a;
	if (a < 40)
	{
		cout << 40 - a;
		return 0;
	}
	if (a < 70)
	{
		cout << 70 - a;
		return 0;
	}
	if (a < 90)
	{
		cout << 90 - a;
		return 0;
	}
	cout << "expert";
	return 0;
}
