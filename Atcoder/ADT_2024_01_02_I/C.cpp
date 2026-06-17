#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>mm;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a]++;
	}
	int ans = 0;
	for(int i =1; i<=1000;++i)
	{
		for (int j = 1; j <= 1000; ++j)
		{
			int p = 4 * i * j + 3 * i + 3 * j;
			if (mm.find(p) == mm.end())
			{
				continue;
			}
			ans += mm[p];
			mm.erase(p);
		}
	}
	cout << n - ans;
	return 0;
}
