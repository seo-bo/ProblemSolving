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
	vector<int> v(4);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		v[0]++;
		for (int j = 3; j >= 0; --j)
		{
			if (j + a >= 4)
			{
				ans += v[j];
				v[j] = 0;
			}
			else
			{
				v[j + a] += v[j];
				v[j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
