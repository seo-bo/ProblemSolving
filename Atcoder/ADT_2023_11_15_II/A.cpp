#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	a = a * 60 + b, c = c * 60 + d;
	cout << ((a <= c) ? "Takahashi" : "Aoki");
	return 0;
}
