#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int> mm;
	vector<int> v = {4, 2, 1};
	int a = 0, b = 0, ans = 0;
	cin >> a >> b;
	for (int i = 0; i < 3; ++i)
	{
		if (a >= v[i])
		{
			mm[v[i]]++;
			a -= v[i];
		}
		if (b >= v[i])
		{
			mm[v[i]]++;
			b -= v[i];
		}
		if (mm[v[i]] >= 1)
		{
			ans += v[i];
		}
	}
	cout << ans;
	return 0;
}
