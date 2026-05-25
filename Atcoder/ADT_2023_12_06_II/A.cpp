#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	if (!a)
	{
		cout << "Silver";
		return 0;
	}
	if (!b)
	{
		cout << "Gold";
		return 0;
	}
	cout << "Alloy";
	return 0;
}
