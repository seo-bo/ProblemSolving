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
	if (n >= 42)
	{
		n++;
	}
	cout << "AGC";
	if (n <= 9)
	{
		cout << 0;
	}
	cout << 0;
	cout << n;
	return 0;
}
