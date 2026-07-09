#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pld> v(n);
	ld time = 0;
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
		time += a / b;
	}
	time /= 2;
	ld len = 0;
	for (auto &[a, b] : v)
	{
		ld pivot = a / b;
		if (pivot >= time)
		{
			len += b * time;
			break;
		}
		len += a;
		time -= pivot;
	}
	cout << fixed << setprecision(15) << len;
	return 0;
}
