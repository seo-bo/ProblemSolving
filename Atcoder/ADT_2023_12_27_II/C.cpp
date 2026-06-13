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
	double p = sqrt(a * a + b * b);
	cout << fixed << setprecision(15) << (double)a / p << ' ' << (double)b / p;
	return 0;
}
