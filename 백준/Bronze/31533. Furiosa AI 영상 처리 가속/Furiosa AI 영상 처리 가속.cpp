#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0;
	double b = 0, c = 0;
	cin >> a >> b >> c;
	double ans = (1LL << 20);
	ans = min({ ans, (b / a) * (double)2, (c / a) * (double)2, max(b / a,c), max(c / a,b) });
	cout << fixed << setprecision(15) << ans;
	return 0;
}